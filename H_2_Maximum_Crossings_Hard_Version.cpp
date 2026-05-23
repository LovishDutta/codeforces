#include<bits/stdc++.h>
using namespace std;
#define int long long
void update(int idx,int l,int r,vector<int>& st,int i){
    if(l==r){
        st[idx]+=1;
        return;
    }
    int mid=(l+r)/2;
    if(i<=mid) update(2*idx+1,l,mid,st,i);
    else update(2*idx+2,mid+1,r,st,i);
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
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,ans=0;
        cin>>n;
        vector<int> arr(n),st(4*(n+1));
        for(int i=0;i<n;i++){
            cin>>arr[i];
            ans+=query(0,0,n,st,arr[i],n);
            update(0,0,n,st,arr[i]);
        }
        cout<<ans<<endl;
    }
}