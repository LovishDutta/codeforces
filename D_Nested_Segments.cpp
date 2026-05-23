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
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>> arr(n);
    vector<int> a,ans(n);
    unordered_map<int,int> mpp;
    mpp.reserve(2*(n+1));
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second.first;
        a.push_back(arr[i].first);
        a.push_back(arr[i].second.first);
        arr[i].second.second=i;
    }
    sort(a.begin(),a.end());
    sort(arr.begin(),arr.end());
    for(int i=0;i<a.size();i++) mpp[a[i]]=i;
    int sz=a.size();
    vector<int> st(4*sz);
    for(int i=n-1;i>=0;i--){
        update(0,0,sz-1,st,mpp[arr[i].second.first],1);
    }
    for(int i=0;i<n;i++){
        update(0,0,sz-1,st,mpp[arr[i].second.first],-1);
       ans[arr[i].second.second]=query(0,0,sz-1,st,0,mpp[arr[i].second.first]);
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<endl;
}