#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int dp[300][90001][2];
int recur(int i,int prev,bool sign,vector<int>&a){
   if(i==a.size()) return 1;
   if(dp[i][prev][sign]!=-1) return dp[i][prev][sign];
    int p=prev;
    if(!sign) p*=-1;
    int ans=0;
    if(p==0) ans=recur(i+1,a[i],1,a)%mod;
    else{
        int add=p+a[i];
        int sub=a[i]-p;
        ans=(ans+recur(i+1,abs(add),add>=0?1:0,a))%mod;
        ans=(ans+recur(i+1,abs(sub),sub>=0?1:0,a))%mod;
    }
    return dp[i][prev][sign]=ans;
}
signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<recur(1,0,1,a);
}