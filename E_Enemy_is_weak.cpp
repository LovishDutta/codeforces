#include<bits/stdc++.h>
using namespace std;
#define int long long
int query(int idx,int l,int r,vector<int>& st,int start,int end){
        if(l>end||r<start) return 0;
        else if(l>=start&&r<=end) return st[idx];
        int mid=(l+r)/2;
        return query(2*idx+1,l,mid,st,start,end)+query(2*idx+2,mid+1,r,st,start,end);
    }
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
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,ans=0;
    cin>>n;
    vector<int> arr(n),arr2(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr2[i]=arr[i];
    }
    sort(arr2.begin(),arr2.end());
    unordered_map<int,int> mpp;
    mpp.reserve(n+1);
    for(int i=0;i<n;i++) mpp[arr2[i]]=i;
    vector<int> st(4*n);
    vector<int> rs(n,0);
    for(int i=n-1;i>=0;i--){
        int val=mpp[arr[i]];
        rs[i]=query(0,0,n-1,st,0,val-1);
        update(0,0,n-1,st,val);
    }
    st.assign(4*n,0);
    for(int i=0;i<n;i++){
        int val=mpp[arr[i]];
        ans+=query(0,0,n-1,st,val+1,n-1)*rs[i];
        update(0,0,n-1,st,val);
    }
    cout<<ans<<endl;
}