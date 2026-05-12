#include<bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> seg;
    SegTree(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
    }
    void build(int idx, int l, int r, vector<int>& arr) {
        if (l == r) {
            seg[idx] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * idx + 1, l, mid, arr);
        build(2 * idx + 2, mid + 1, r, arr);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    int query(int idx, int l, int r, int ql, int qr, int val) {
        if (r < ql || l > qr || seg[idx] >= val)
            return -1;
        if (l == r)
            return l;
        int mid = (l + r) >> 1;
        int right = query(2 * idx + 2, mid + 1, r, ql, qr, val);
        if (right != -1)
            return right;
        return query(2 * idx + 1, l, mid, ql, qr, val);
    }
    int get(int l, int r, int val) {
        return query(0, 0, n - 1, l, r, val);
    }
};
class dsu{
    public:
    vector<int> par,size;
    dsu(int n){
        par.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) par[i]=i;
    }
    int upar(int node){
        if(node==par[node]) return node;
        return par[node]=upar(par[node]);
    }
    void uni(int n1,int n2){
        int a=upar(n1),b=upar(n2);
        if(a==b) return;
        if(size[a]<size[b]){
            par[a]=b;
            size[b]+=size[a];
        }
        else{
            par[b]=a;
            size[a]+=size[b];
        }
    }
};
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        SegTree st(arr);
       int maxi=arr[0],idx=0;
       vector<int> ans(n);
       dsu ds(n);
       for(int i=0;i<n;i++){
        if(arr[i]>maxi){
            maxi=arr[i];
            idx=i;
        }
        if(idx!=i) ds.uni(idx,i);
        int id=st.get(i+2, n-1, arr[i]);
        if(id!=-1){
            ds.uni(i,id);
        }
       }
       map<int,int> mpp;
       for(int i=0;i<ds.par.size();i++){
        mpp[ds.upar(i)]=max(mpp[ds.upar(i)],arr[i]);
       }
       for(int i=0;i<n;i++){
        cout<<mpp[ds.upar(i)]<<" ";
       }
       cout<<endl;
    }
}