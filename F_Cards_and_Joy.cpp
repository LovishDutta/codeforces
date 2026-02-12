#include<bits/stdc++.h>
using namespace std;
int dp[501][5001];
int recur(int pep,int freq,vector<int>& joy,int& k){
    if(pep==0||freq==0) return 0;
    if(dp[pep][freq]!=-1) return dp[pep][freq];
    int ans=0;
    for(int i=0;i<=min(freq,k);i++){
        ans=max(ans,joy[i]+recur(pep-1,freq-i,joy,k));
    }
    return dp[pep][freq]=ans;
}
int main(){
        int n,k,a;
        cin>>n>>k;
        map<int,int> nums,pepfav;
        vector<int> joy(1,0);
        for(int i=0;i<n*k;i++){
            cin>>a;
            nums[a]++;
        }
        for(int i=0;i<n;i++){
            cin>>a;
            pepfav[a]++;
        }
        for(int i=0;i<k;i++){
            cin>>a;
            joy.push_back(a);
        }
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(auto &it:pepfav){
            ans+=recur(it.second,nums[it.first],joy,k);
        }
        cout<<ans<<endl;
}