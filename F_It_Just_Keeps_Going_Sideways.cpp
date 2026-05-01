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
struct SumTree {
    int n;
    vector<long long> tree, lazy;

    SumTree(int n) {
        this->n = n;
        tree.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += (r - l + 1) * lazy[node];
            if (l != r) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        push(node, l, r);
        if (r < ql || l > qr) return;

        if (ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }

        int mid = (l + r) >> 1;
        update(2*node, l, mid, ql, qr, val);
        update(2*node+1, mid+1, r, ql, qr, val);

        tree[node] = tree[2*node] + tree[2*node+1];
    }

    long long query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (r < ql || l > qr) return 0;

        if (ql <= l && r <= qr) return tree[node];

        int mid = (l + r) >> 1;
        return query(2*node, l, mid, ql, qr) +
               query(2*node+1, mid+1, r, ql, qr);
    }

    void update(int l, int r, long long val) {
        update(1, 1, n, l, r, val);
    }

    long long query(int l, int r) {
        return query(1, 1, n, l, r);
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
        SumTree sumt(n+1);
        sumt.update(1,arr[n-1],1);
        for(int i=n-2;i>=0;i--){
            if(arr[i]>flrange[i+1]){
                flrange[i]=flrange[i+1];
                ans+=(arr[i]*(n-i-1)-sumt.query(1,arr[i]));
                rem[i]=false;
            }
            else{
                flrange[i]=arr[i];
            }
            sumt.update(1,arr[i],1);
            //cout<<flrange[i]<<" ";
            //cout<<i<<" "<<ans<<endl;
        }
        SegTree st(arr);
        for(int i=n-1;i>0;i--){
            if(rem[i]) a=max(a,st.query(0,i-1,arr[i]));
            //cout<<i<<" "<<a<<endl;
        }
        //cout<<a<<endl;
        cout<<ans+a<<endl;
    }
}