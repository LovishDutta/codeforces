#include<bits/stdc++.h>
using namespace std;
#define int long long
int query(int idx,int l,int r,vector<int>& st,vector<int>& lazy,int i,vector<int>& a,vector<int>& b){
    if(lazy[idx]!=-1){
        st[idx]=lazy[idx];
        if(l!=r){
            int mid=(l+r)/2;
            lazy[2*idx+1]=lazy[idx];
            lazy[2*idx+2]=lazy[idx]+mid+1-l;
        }
        lazy[idx]=-1;
    }
    if(l==r){
        if(st[idx]==-1) return b[l];
        else return a[st[idx]];
    }
    int mid=(l+r)/2;
    if(i<=mid) return query(2*idx+1,l,mid,st,lazy,i,a,b);
    return query(2*idx+2,mid+1,r,st,lazy,i,a,b);
}
void update(int idx,int l,int r,vector<int>& st,vector<int>& lazy,int start,int end,int val){
    if(lazy[idx]!=-1){
        st[idx]=lazy[idx];
        if(l!=r){
            int mid=(l+r)/2;
            lazy[2*idx+1]=lazy[idx];
            lazy[2*idx+2]=lazy[idx]+mid+1-l;
        }
        lazy[idx]=-1;
    }
    if(l>end||r<start) return;
    else if(l>=start&&r<=end){
        st[idx]=val+(l-start);
        if(l!=r){
            int mid=(l+r)/2;
            lazy[2*idx+1]=st[idx];
            lazy[2*idx+2]=st[idx]+(mid+1-l);
        }
        return;
    }
    int mid=(l+r)/2;
    update(2*idx+1,l,mid,st,lazy,start,end,val);
    update(2*idx+2,mid+1,r,st,lazy,start,end,val);
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,t,x,y,k;
    cin>>n>>m;
    vector<int> a(n),b(n),st(4*n,-1),lazy(4*n,-1);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    while(m--){
        cin>>t;
        if(t==1){
            cin>>x>>y>>k;
            update(0,0,n-1,st,lazy,y-1,y-1+k-1,x-1);
        }
        else{
            cin>>x;
            cout<<query(0,0,n-1,st,lazy,x-1,a,b)<<endl;
        }
    }
}