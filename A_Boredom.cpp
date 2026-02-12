#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[100002];
int recur(int i,vector<int>& arr,vector<int>& freq){
    if(i>=arr.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int notdel=recur(i+1,arr,freq);
    int del=freq[i]*arr[i];
    if(i<arr.size()-1&&arr[i+1]==arr[i]+1) del+=recur(i+2,arr,freq);
    else del+=recur(i+1,arr,freq);
    return dp[i]=max(del,notdel);
}
signed main(){ 
        int n;
        cin>>n;
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            mpp[a]++;
        }
        vector<int> arr;
        vector<int> freq;
        for(auto& it:mpp){
            arr.push_back(it.first);
            freq.push_back(it.second);
        }
        memset(dp,-1,sizeof(dp));
    cout<<recur(0,arr,freq);
}