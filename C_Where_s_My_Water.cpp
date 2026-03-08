#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(int idx,int cnt,int prev,vector<int>& arr,vector<pair<int,int>>& vec,vector<int>& pref,vector<vector<vector<int>>>& dp,int m){
    if(idx>=arr.size()||cnt==2) return 0;
    if(dp[cnt][idx][prev]!=-1) return dp[cnt][idx][prev];
    int notpick=recur(idx+1,cnt,prev,arr,vec,pref,dp,m);
    int prevv=(vec[idx].first==0?0:(pref[vec[idx].first-1]-(vec[idx].first)*(m-arr[vec[idx].first])));
    if(cnt!=0&&prev>vec[idx].first) prevv=pref[prev];
    int pick=(pref[idx]-prevv)+(pref[vec[idx].second]-pref[idx]+(arr.size()-1-vec[idx].second)*(m-arr[vec[idx].second]))+recur(vec[idx].second+1,cnt+1,vec[idx].second,arr,vec,pref,dp,m);
    return dp[cnt][idx][prev]=max(pick,notpick);
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m;
        cin>>n>>m;
        vector<int> arr(n);
        vector<int> pref(n);
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
             cin>>arr[i];
             if(i==0) pref[0]=(m-arr[0]);
             else pref[i]=pref[i-1]+(m-arr[i]);
        }
        for(int i=0;i<n;i++){
            int j=i,k=i;
            while(j<n-1&&arr[j+1]>=arr[j]) j++;
            while(k>0&&arr[k-1]>=arr[k]) k--;
            vec.push_back({k,j});
        }
        vector<vector<vector<int>>> dp(3,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        cout<<recur(0,0,0,arr,vec,pref,dp,m)<<endl;
    }
}