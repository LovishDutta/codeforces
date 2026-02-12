#include<bits/stdc++.h>
using namespace std;
int dp[3001][3000][4];
int recur(int idx,int prev,int cnt,vector<int>& s,vector<int>& c){
    if(idx==s.size())  return (cnt==3?0:1e9);
    if(dp[prev][idx][cnt]!=-1) return dp[prev][idx][cnt];
    int notpick=recur(idx+1,prev,cnt,s,c);
    int pick=1e9;
    if((prev==s.size()||s[prev]<s[idx])&&cnt<3) pick=c[idx]+recur(idx+1,idx,cnt+1,s,c);
    return dp[prev][idx][cnt]=min(pick,notpick);
}
int main(){
    int n;
    cin>>n;
    vector<int> s(n);
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++) cin>>c[i];
    memset(dp,-1,sizeof(dp));
    int ans=recur(0,n,0,s,c);
    cout<<(ans==1e9?-1:ans);
}