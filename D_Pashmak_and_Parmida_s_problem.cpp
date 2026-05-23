#include<bits/stdc++.h>
using namespace std;
#define int long long
void update(int idx,int l,int r,vector<int>& st,int i,int val){
        if(l==r){
            st[idx]+=val;
            return;
        }
        int mid=(l+r)/2;
        if(i<=mid) update(2*idx+1,l,mid,st,i,val);
        else update(2*idx+2,mid+1,r,st,i,val);
        st[idx]=st[2*idx+1]+st[2*idx+2];
    }
int query(int idx,int l,int r,vector<int>& st,int start,int end){
        if(l>end||r<start) return 0;
        else if(l>=start&&r<=end) return st[idx];
        int mid=(l+r)/2;
        return query(2*idx+1,l,mid,st,start,end)+query(2*idx+2,mid+1,r,st,start,end);
    }
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,ans=0;
    cin>>n;
    vector<int> arr(n),st(4*(n+1)),rf(n);
    unordered_map<int,int> mpp,cc; 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=n-1;i>=0;i--){
        mpp[arr[i]]++;
        rf[i]=mpp[arr[i]];
        update(0,0,n,st,mpp[arr[i]],1);
    }
    mpp.clear();
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        int val=mpp[arr[i]];
        update(0,0,n,st,rf[i],-1);
        ans+=query(0,0,n,st,0,val-1);
    }
    cout<<ans<<endl;
}