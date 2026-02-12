#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,k;
        cin>>n>>k;
        vector<int> q(n);
        vector<int> r(n);
        for(int i=0;i<n;i++) cin>>q[i];
        for(int i=0;i<n;i++) cin>>r[i];
        sort(q.begin(),q.end());
        sort(r.begin(),r.end());
        int i=0;
        int cnt=0;
        for(int j=n-1;j>=0;j--){
            if(r[j]<k){
                int y=(k-r[j])/q[i];
                int x=y*q[i]+r[j];
                if(y>0&&y<x&&x<=k&&(x%y==r[j])){
                    cnt++;
                   // cout<<x<<" "<<y<<endl;
                    i++;
                }
                //else break;
            }
        }
        cout<<cnt<<endl;
    }
}