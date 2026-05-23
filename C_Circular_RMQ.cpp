#include<bits/stdc++.h>
using namespace std;
#define int long long
void bt(int idx,int l,int r,vector<int>& a,vector<int>& st){
    if(l==r){
        st[idx]=a[l];
        return;
    }
    int mid=(l+r)/2;
    bt(2*idx+1,l,mid,a,st);
    bt(2*idx+2,mid+1,r,a,st);
    st[idx]=min(st[2*idx+1],st[2*idx+2]);
}
void update(int idx,int l,int r,vector<int>& lazy,vector<int>& st,int start,int end,int v){
    if(lazy[idx]!=0){
        st[idx]+=lazy[idx];
        if(l!=r){
            lazy[2*idx+1]+=lazy[idx];
            lazy[2*idx+2]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    if(l>end||r<start) return;
    else if(l>=start&r<=end){
        st[idx]+=v;
        if(l!=r){
            lazy[2*idx+1]+=v;
            lazy[2*idx+2]+=v;
        }
        return;
    }
    int mid=(l+r)/2;
    update(2*idx+1,l,mid,lazy,st,start,end,v);
    update(2*idx+2,mid+1,r,lazy,st,start,end,v);
    st[idx]=min(st[2*idx+1],st[2*idx+2]);
}
int query(int idx,int l,int r,vector<int>& lazy,vector<int>& st,int start,int end){
    if(lazy[idx]!=0){
        st[idx]+=lazy[idx];
        if(l!=r){
            lazy[2*idx+1]+=lazy[idx];
            lazy[2*idx+2]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    if(l>end||r<start) return 1e12;
    else if(l>=start&r<=end){
        return st[idx];
    }
    int mid=(l+r)/2;
    int a=query(2*idx+1,l,mid,lazy,st,start,end);
    int b=query(2*idx+2,mid+1,r,lazy,st,start,end);
    return min(a,b);
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n),st(4*n),lazy(4*n);
    for(int i = 0; i < n; i++) cin >> a[i];
    bt(0,0,n-1,a,st);
    int m;
    cin >> m;
    cin.ignore();
    for(int i = 0; i < m; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> q;
        int x;
        while(ss >> x) q.push_back(x);
        if(q.size() == 2) {
            int l = q[0];
            int r = q[1];
            if(r>=l) cout<<query(0,0,n-1,lazy,st,l,r)<<endl;
            else{
                int a=query(0,0,n-1,lazy,st,l,n-1);
                int b=query(0,0,n-1,lazy,st,0,r);
                cout<<min(a,b)<<endl;
            }
        }
        else {
            int l = q[0];
            int r = q[1];
            int v = q[2];
            if(r>=l) update(0,0,n-1,lazy,st,l,r,v);
            else{
                update(0,0,n-1,lazy,st,l,n-1,v);
                update(0,0,n-1,lazy,st,0,r,v);
            }
        }
    }
}