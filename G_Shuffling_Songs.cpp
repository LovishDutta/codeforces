#include<bits/stdc++.h>
using namespace std;

int dp[(1<<16)+2][18];
int recur(int pickstr,int prev,vector<vector<int>>& arr){
    int ans=0;
    if(dp[pickstr][prev]!=-1) return dp[pickstr][prev];
    for(int i=0;i<arr.size();i++){
        if(i==prev) continue;
        if(arr[i][0]==arr[prev][0]||arr[i][1]==arr[prev][1]){
            if((pickstr&(1<<i))==0){
                ans=max(ans,1+recur(pickstr|(1<<i),i,arr));
            }
        }
    }
    return dp[pickstr][prev]=ans; 
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<vector<string>> ip(n,vector<string>(2));
        unordered_map<string,int> mppG;
        unordered_map<string,int> mppS;
    
    int cnt1=1,cnt2=1;
    for(int i=0;i<n;i++){
        cin>>ip[i][0];
        cin>>ip[i][1];
        if(mppG[ip[i][0]]==0){
            mppG[ip[i][0]]=cnt1++;
        }
        if(mppS[ip[i][1]]==0){
            mppS[ip[i][1]]=cnt2++;
        }
    } 
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i=0;i<n;i++){
        arr[i][0]=mppG[ip[i][0]];
        arr[i][1]=mppS[ip[i][1]];
    }
    int ans=0;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        ans=max(ans,1+recur((1<<i),i,arr));
    }
    cout<<n-ans<<endl;
    }
}