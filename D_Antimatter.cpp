#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int dp[1000][10001][3][2];
int recur(int i,int sum,int st,bool sign,vector<int>& arr){
    if(i==arr.size()||st==2) return (st!=0&&sum==0);
    if(dp[i][sum][st][sign]!=-1) return dp[i][sum][st][sign];
    if(st==0){
        int ns=recur(i+1,sum,st,sign,arr);
        int s=1;
        if(!sign) s=-1;
        int add=sum*s+arr[i];
        int sub=sum*s-arr[i];
        int s1=recur(i+1,abs(add),1,add>0?1:0,arr);
        int s2=recur(i+1,abs(sub),1,sub>0?1:0,arr);
        return dp[i][sum][st][sign]=((ns+s1)%mod+s2)%mod;
    }
    else if(st==1){
        int me=0,ame=0;
        int s=1;
        if(!sign) s=-1;
        int add=sum*s+arr[i];
        int sub=sum*s-arr[i];
        int m=recur(i+1,abs(add),1,add>0?1:0,arr);
        if(i<arr.size()-1) me=recur(i+1,abs(add),2,add>0?1:0,arr);
        int am=recur(i+1,abs(sub),1,sub>0?1:0,arr);
        if(i<arr.size()-1) ame=recur(i+1,abs(sub),2,sub>0?1:0,arr);
        return dp[i][sum][st][sign]=((m+me)%mod+(am+ame)%mod)%mod;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<recur(0,0,0,1,arr);
}