#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>a,b,mini,maxi;
void bt(int idx,int l,int r){
    if(l==r){
        mini[idx]=b[l];
        maxi[idx]=a[r];
        return;
    }
    int mid=(l+r)/2;
    bt(2*idx+1,l,mid);
    bt(2*idx+2,mid+1,r);
    mini[idx]=min(mini[2*idx+1],mini[2*idx+2]);
    maxi[idx]=max(maxi[2*idx+1],maxi[2*idx+2]);
}
pair<int,int> q(int idx,int l,int r,int st,int end){
    if(l>end||r<st) return {-1e12,1e12};
    else if(l>=st&&r<=end) return {maxi[idx],mini[idx]};
    int mid=(l+r)/2;
    pair<int,int> le=q(2*idx+1,l,mid,st,end);
    pair<int,int> ri=q(2*idx+2,mid+1,r,st,end);
    return {max(le.first,ri.first),min(le.second,ri.second)};
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n,cnt=0;
        cin>>n;
        a.resize(n);
        b.resize(n);
        mini.resize(4*n);
        maxi.resize(4*n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        bt(0,0,n-1);
        for(int i=0;i<n;i++){
            int low=i,high=n-1,ans=-1,l=i,h=n-1,ans2=-1;
            while(low<=high){
                int mid=(low+high)/2;
                pair<int,int> query=q(0,0,n-1,i,mid);
                int qr=query.first-query.second;
                if(qr>=0){
                    if(qr==0) ans=mid;
                    high=mid-1;
                }
                else low=mid+1;
            }
            if(ans==-1) continue;
            while(l<=h){
                int mid=(l+h)/2;
                pair<int,int> query=q(0,0,n-1,i,mid);
                int qr=query.first-query.second;
                if(qr<=0){
                    if(qr==0) ans2=mid;
                    l=mid+1;
                }
                else h=mid-1;
            }
            cnt+=(ans2-ans+1);
        }
        cout<<cnt<<endl;
}