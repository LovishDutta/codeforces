#include<bits/stdc++.h>
using namespace std;
int recur(int i,int num,vector<int>& arr,int& final,vector<vector<int>>& dp){
    if(i==arr.size()) return (num==final)?0:1e6;
    if(dp[i][num]!=-1) return dp[i][num];
    int pick=1+recur(i+1,__gcd(num==0?arr[i]:num,arr[i]),arr,final,dp);
    int notpick=recur(i+1,num,arr,final,dp);
    return dp[i][num]=min(pick,notpick);
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        cin>>arr[0];
        int final=arr[0],maxi=arr[0];
        for(int i=1;i<n;i++){
            cin>>arr[i];
            final=__gcd(final,arr[i]);
            maxi=max(maxi,arr[i]);
        }
        vector<vector<int>> dp(n,vector<int>(maxi+1,-1));
        int cnt=recur(0,0,arr,final,dp)-1;
        if(cnt>0) cnt--;
        for(int i=0;i<n;i++){
            if(arr[i]!=final) cnt++;
        }
        cout<<cnt<<endl;

    }
}