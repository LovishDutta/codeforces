#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> mat(4,vector<int>(4,0));
int dp[1001][2002][4];
int mod=998244353;
int recur(int i,int k,int prev,int& n,int& target){
   if(i==n) return k==target;
   if(dp[i][k][prev]!=-1) return dp[i][k][prev];
   int ans=0;
   for(int j=0;j<4;j++){
       int a=mat[prev][j];
    if(a+k<=target) ans=(ans+recur(i+1,a+k,j,n,target))%mod;
   }
   return dp[i][k][prev]=ans%mod;
}
signed main(){
    int n,k;
    cin>>n>>k;
    mat[0][1]=mat[0][2]=mat[0][3]=mat[3][0]=mat[3][1]=mat[3][2]=1;
    mat[1][2]=mat[2][1]=2;
    memset(dp,-1,sizeof(dp));
    cout<<(recur(1,1,0,n,k)+recur(1,2,1,n,k)+recur(1,2,2,n,k)+recur(1,1,3,n,k))%mod;
}