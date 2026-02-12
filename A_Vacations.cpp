#include<bits/stdc++.h>
using namespace std;
int dp[101][3];
int recur(vector<int>& arr,int i,int prev){
    if(i==arr.size()) return 0;
    if(dp[i][prev]!=-1) return dp[i][prev];
    int con=1e9,gym=1e9;
    if(prev==1||prev==0){
        if(arr[i]==2||arr[i]==0) con=1+recur(arr,i+1,0);
        else con=recur(arr,i+1,2);
    }
    if(prev==2||prev==0){
        if(arr[i]==1||arr[i]==0) gym=1+recur(arr,i+1,0);
        else gym=recur(arr,i+1,1);
    }
    return dp[i][prev]=min(con,gym);
}
int main(){

        int n;
        cin>>n;
        vector<int> arr(n);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<recur(arr,0,0);
    
}