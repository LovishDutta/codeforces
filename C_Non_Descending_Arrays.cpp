#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int dp[102][2];
int recur(vector<int>& a,vector<int>& b,int i,bool swap){
    if(i==a.size()) return 1;
    if(dp[i][swap]!=-1) return dp[i][swap];
    int s=0,ns=0;
    int preva=-1,prevb=-1;
    if(i>0){
       if(swap){
        preva=a[i-1];
        prevb=b[i-1];
       }
       else{
        preva=b[i-1];
        prevb=a[i-1];
       }
    }
    if(a[i]>=preva&&b[i]>=prevb) ns=recur(a,b,i+1,false)%mod;
    if(a[i]>=prevb&&b[i]>=preva) s=recur(a,b,i+1,true)%mod;
    return dp[i][swap]=(s+ns)%mod;
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        memset(dp,-1,sizeof(dp));
        cout<<recur(a,b,0,false)<<endl;
    }
}