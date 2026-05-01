#include<bits/stdc++.h>
using namespace std;
#define int long long
struct SegTree {
    int n;
    vector<vector<int>> tree;

    SegTree(vector<int>& a) {
        n = a.size();
        tree.resize(4*n);
        build(1, 0, n-1, a);
    }

    void build(int node, int l, int r, vector<int>& a) {
        if (l == r) {
            tree[node] = {a[l]};
            return;
        }
        int mid = (l + r) >> 1;
        build(2*node, l, mid, a);
        build(2*node+1, mid+1, r, a);
        merge(tree[2*node].begin(), tree[2*node].end(),
              tree[2*node+1].begin(), tree[2*node+1].end(),
              back_inserter(tree[node]));
    }

    int query(int node, int l, int r, int ql, int qr, int val) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) {
            return tree[node].end() - lower_bound(tree[node].begin(), tree[node].end(), val);
        }
        int mid = (l + r) >> 1;
        return query(2*node, l, mid, ql, qr, val) +
               query(2*node+1, mid+1, r, ql, qr, val);
    }

    int query(int l, int r, int val) {
        return query(1, 0, n-1, l, r, val);
    }
};
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,ans=0,a=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<int> flrange(n);
        vector<int> rem(n,true);
        flrange[n-1]=arr[n-1];
        //rem[n-1]=false;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>flrange[i+1]){
                flrange[i]=flrange[i+1];
                ans+=(arr[i]-flrange[i]);
                rem[i]=false;
            }
            else{
                flrange[i]=arr[i];
            }
            //cout<<flrange[i]<<" ";
        }
        SegTree st(flrange);
        for(int i=n-1;i>0;i--){
            if(rem[i]) a=max(a,st.query(0,i-1,flrange[i]));
           // cout<<i<<" "<<a<<endl;
        }
        cout<<ans+a<<endl;
    }
}