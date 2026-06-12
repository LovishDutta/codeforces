#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> st,lazy;
int query(int start,int end,int idx,int low,int high){
        if(lazy[idx] != -1){
        st[idx] = lazy[idx] * (high - low + 1);
        if(low != high){
            lazy[2*idx+1] = lazy[idx];
            lazy[2*idx+2] = lazy[idx];
        }
        lazy[idx] = -1;
        }
        if(end<low||start>high) return 0;
        else if(end>=high&&start<=low) return st[idx];
        else{
            int mid=(low+high)/2;
            return query(start,end,2*idx+1,low,mid)+query(start,end,2*idx+2,mid+1,high);
        }
    }
void updaterange(int i,int l,int r,int start,int end,int val){
        if(lazy[i]!=-1){
            st[i]=lazy[i]* (r - l + 1);
            if(l!=r){
                lazy[2*i+1]=lazy[i];
                lazy[2*i+2]=lazy[i];
            }
            lazy[i]=-1;
        }
        if(l>end||r<start) return;
        else if(l>=start&&r<=end){
            st[i]=val* (r - l + 1);
            if(l!=r){
                lazy[2*i+1]=val;
                lazy[2*i+2]=val;
            }
            return;
        }
        int mid=(l+r)/2;
        updaterange(2*i+1,l,mid,start,end,val);
        updaterange(2*i+2,mid+1,r,start,end,val);
        st[i]=st[2*i+1]+st[2*i+2];
    }
int funct(int n){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        int q=query(mid,n-1,0,0,n-1);
        if(q<n-mid) low=mid+1;
        else high=mid-1;
    }
    return high;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k,a,b,c,ones=0;
        cin>>n>>k;
        st.assign(4*n,0);
        lazy.assign(4*n,-1);
        for(int i=0;i<k;i++){
            cin>>a;
            if(a==0){
                cin>>b>>c;
                int q=query(b-1,c-1,0,0,n-1);
                ones-=q;
                updaterange(0,0,n-1,b-1,c-1,0);
                int fzero=funct(n);
                if(fzero==-1) cout<<1<<endl;
                else cout<<query(0,fzero,0,0,n-1)+1<<endl;
            }
            else if(a==1){
                cin>>b>>c;
                int q=query(b-1,c-1,0,0,n-1);
                ones+=((c-b+1)-q);
                updaterange(0,0,n-1,b-1,c-1,1);
                int fzero=funct(n);
                if(fzero==-1) cout<<1<<endl;
                else cout<<query(0,fzero,0,0,n-1)+1<<endl;
            }
            else{
                int zeros=n-ones;
                updaterange(0,0,n-1,0,zeros-1,0);
                updaterange(0,0,n-1,zeros,n-1,1);
                cout<<1<<endl;
            }
        }
    }
}