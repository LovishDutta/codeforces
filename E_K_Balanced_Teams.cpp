#include<bits/stdc++.h>
using namespace std;
int dp[5001][5001];
int recur(int idx,vector<int>& next,int k){
    if(idx==next.size()) return 0;
    if(dp[idx][k]!=-1) return dp[idx][k];
    int np=recur(idx+1,next,k),p=0;
    if(k>0) p=(next[idx]-idx+1)+recur(next[idx]+1,next,k-1);
    return dp[idx][k]=max(p,np);
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    vector<int> next(n);
    for(int i=0;i<n;i++){
        int idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]-arr[i]<=5) idx=j;
            else break;
        }
        next[i]=idx;
    }
    memset(dp,-1,sizeof(dp));
    cout<<recur(0,next,k);
}