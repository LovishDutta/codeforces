#include<bits/stdc++.h>
using namespace std;
int recur(int idx,bool turn,vector<int>& arr,vector<vector<int>>& dp){
    if(idx>=arr.size()) return 0;
    if(dp[idx][turn]!=-1) return dp[idx][turn];
    int one=0,two=0;
    one=(turn&&arr[idx]==1)+recur(idx+1,!turn,arr,dp);
    two=(turn&&arr[idx]==1)+(idx<arr.size()-1&&turn&&arr[idx+1]==1)+recur(idx+2,!turn,arr,dp);
    return dp[idx][turn]=min(one,two);
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        cout<<recur(0,true,arr,dp)<<endl;
    }
}