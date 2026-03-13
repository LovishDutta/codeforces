#include<bits/stdc++.h>
using namespace std;
#define int long long
class SegmentTree {
public:
    int n;
    vector<int> tree;
    vector<long long> arr;
    SegmentTree(vector<long long>& a) {
        arr = a;
        n = a.size();
        tree.resize(4*n);
        build(0,0,n-1);
    }
    void build(int node,int l,int r){
        if(l==r){
            tree[node]=l;
            return;
        }
        int mid=(l+r)/2;
        build(2*node+1,l,mid);
        build(2*node+2,mid+1,r);
        int left=tree[2*node+1];
        int right=tree[2*node+2];
        tree[node] = (arr[left] >= arr[right] ? left : right);
    }
    int query(int node,int start,int end,int l,int r){
        if(r < start || end < l)
            return -1;
        if(l <= start && end <= r)
            return tree[node];
        int mid=(start+end)/2;
        int left=query(2*node+1,start,mid,l,r);
        int right=query(2*node+2,mid+1,end,l,r);
        if(left==-1) return right;
        if(right==-1) return left;
        return (arr[left] >= arr[right] ? left : right);
    }
    int rangeMaxIndex(int l,int r){
        return query(0,0,n-1,l,r);
    }
};
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m,ans=0;
        cin>>n>>m;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        SegmentTree st(arr);
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            int a=(m-arr[i]),maxi=arr[i],maxi2=arr[i];
            for(int j=i+1;j<n;j++){
                maxi=max(maxi,arr[j]);
                a+=(m-maxi);
            }
            for(int j=i-1;j>=0;j--){
                maxi2=max(maxi2,arr[j]);
                a+=(m-maxi2);
            }
            vec[i]=a;
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ans=max(ans,vec[i]+vec[j]-vec[st.rangeMaxIndex(i,j)]);
            }
        }
        cout<<ans<<endl;
    }
}