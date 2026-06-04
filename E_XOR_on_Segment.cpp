#include<bits/stdc++.h>
using namespace std;
#define int long long
void bt(int idx,int l,int r,vector<vector<int>>& st,vector<int>& arr){
    if(l==r){
        int ele=arr[l],cnt=0;
        while(ele>0){
            if(ele%2) st[idx][cnt]++;
            cnt++;
            ele/=2;
        }
        return;
    }
    int mid=(l+r)/2;
    bt(2*idx+1,l,mid,st,arr);
    bt(2*idx+2,mid+1,r,st,arr);
    for(int i=0;i<32;i++) st[idx][i]=st[2*idx+1][i]+st[2*idx+2][i];
}
int query(int idx,int l,int r,vector<vector<int>>& st,vector<int>& lazy,int start,int end){
        if(lazy[idx]!=0){
            for(int i=0;i<32;i++){
                if((lazy[idx]&(1LL<<i))>0) st[idx][i]=(r-l+1)-st[idx][i];
            }
            if(l!=r){
                lazy[2*idx+1]^=lazy[idx];
                lazy[2*idx+2]^=lazy[idx];
            }
            lazy[idx]=0;
        }
        if(l>end||r<start) return 0;
        else if(l>=start&&r<=end){
            int sum=0;
            for(int i=0;i<32;i++){
                sum+=(1LL<<i)*st[idx][i];
            }
            return sum;
        }
        int mid=(l+r)/2;
        return query(2*idx+1,l,mid,st,lazy,start,end)+query(2*idx+2,mid+1,r,st,lazy,start,end);
    }
void update(int idx,int l,int r,vector<vector<int>>& st,vector<int>& lazy,int start,int end,int val){
        if(lazy[idx]!=0){
            for(int i=0;i<32;i++){
                if((lazy[idx]&(1LL<<i))>0) st[idx][i]=(r-l+1)-st[idx][i];
            }
            if(l!=r){
                lazy[2*idx+1]^=lazy[idx];
                lazy[2*idx+2]^=lazy[idx];
            }
            lazy[idx]=0;
        }
        if(l>end||r<start) return;
        else if(l>=start&&r<=end){
            for(int i=0;i<32;i++){
                if((val&(1LL<<i))>0) st[idx][i]=(r-l+1)-st[idx][i];
            }
            if(l!=r){
                lazy[2*idx+1]^=val;
                lazy[2*idx+2]^=val;
            }
            return;
        }
        int mid=(l+r)/2;
        update(2*idx+1,l,mid,st,lazy,start,end,val);
        update(2*idx+2,mid+1,r,st,lazy,start,end,val);
        for(int i=0;i<32;i++) st[idx][i]=st[2*idx+1][i]+st[2*idx+2][i];
    }
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,a,l,r,v;
    cin>>n;
    vector<int> arr(n),lazy(4*n);
    vector<vector<int>> st(4*n,vector<int>(32));
    for(int i=0;i<n;i++) cin>>arr[i];
    bt(0,0,n-1,st,arr);
    cin>>m;
    while(m--){
        cin>>a;
        if(a==1){
            cin>>l>>r;
            cout<<query(0,0,n-1,st,lazy,l-1,r-1)<<endl;;
        }
        else{
            cin>>l>>r>>v;
            update(0,0,n-1,st,lazy,l-1,r-1,v);
        }
    }
}