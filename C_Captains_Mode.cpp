#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[20][(1<<20)];
int recur(int idx,int ban,vector<vector<int>>& v,vector<int>& arr){
    if(idx==v.size()) return 0;
    if(dp[idx][ban]!=-1) return dp[idx][ban];
    if(v[idx][1]==1){
        if(v[idx][0]==0){
            int ans=-1e12;
            for(int i=min(19LL,(int)arr.size()-1);i>=0;i--){
                if((ban&(1<<i))==0){
                    ans=max(arr[i]+recur(idx+1,(ban|(1<<i)),v,arr),ans);
                }
            }
            return dp[idx][ban]=ans;
        }
        else{
            int ans=recur(idx+1,ban,v,arr);
            for(int i=min(19LL,(int)arr.size()-1);i>=0;i--){
                if((ban&(1<<i))==0){
                    ans=max(recur(idx+1,(ban|(1<<i)),v,arr),ans);
                }
            }
            return dp[idx][ban]=ans;
        }
    }
    else{
        if(v[idx][0]==0){
            int ans=1e12;
            for(int i=min(19LL,(int)arr.size()-1);i>=0;i--){
                if((ban&(1<<i))==0){
                    ans=min(-arr[i]+recur(idx+1,(ban|(1<<i)),v,arr),ans);
                }
            }
            return dp[idx][ban]=ans;
        }
        else{
            int ans=recur(idx+1,ban,v,arr);
            for(int i=min(19LL,(int)arr.size()-1);i>=0;i--){
                if((ban&(1<<i))==0){
                    ans=min(recur(idx+1,(ban|(1<<i)),v,arr),ans);
                }
            }
            return dp[idx][ban]=ans;
        }
    }
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>m;
    vector<vector<int>> v(m,vector<int>(2));
    for(int i=0;i<m;i++){
        char c;
        cin>>c>>v[i][1];
        if(c=='p') v[i][0]=0;
        else v[i][0]=1;
    }
    sort(arr.rbegin(),arr.rend());
    memset(dp,-1,sizeof(dp));
    cout<<recur(0,0,v,arr);
}