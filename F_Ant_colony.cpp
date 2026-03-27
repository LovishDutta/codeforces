#include<bits/stdc++.h>
using namespace std;
#define int long long
class SegmentTree {
public:
    vector<int> tree;
    int n;
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4*n);
        build(0,0,n-1,arr);
    }
    int gcd_val(int a,int b){
        if(b==0) return a;
        return gcd_val(b,a%b);
    }
    void build(int node,int start,int end,vector<int>& arr){
        if(start==end){
            tree[node] = arr[start];
            return;
        }
        int mid = (start+end)/2;
        build(2*node+1,start,mid,arr);
        build(2*node+2,mid+1,end,arr);
        tree[node] = gcd_val(tree[2*node+1],tree[2*node+2]);
    }
    int query(int node,int start,int end,int l,int r){
        if(r < start || end < l)
            return 0; 
        if(l <= start && end <= r)
            return tree[node];
        int mid = (start+end)/2;
        int left = query(2*node+1,start,mid,l,r);
        int right = query(2*node+2,mid+1,end,l,r);

        return gcd_val(left,right);
    }
    int getGCD(int l,int r){
        return query(0,0,n-1,l,r);
    }
};
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,t,a,b;
    cin>>n;
    vector<int> arr(n);
    map<int,vector<int>> mpp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mpp[arr[i]].push_back(i);
    }
    SegmentTree st(arr);
    cin>>t;
    while(t--){
        cin>>a>>b;
        int gc=st.getGCD(a-1,b-1);
        int r=upper_bound(mpp[gc].begin(),mpp[gc].end(),b-1)-mpp[gc].begin();
        int l=lower_bound(mpp[gc].begin(),mpp[gc].end(),a-1)-mpp[gc].begin();
        if(l==mpp[gc].size()||mpp[gc][l]>(b-1)) cout<<(b-a+1)<<endl;
        else cout<<(b-a-r+l+1)<<endl;
    }
}