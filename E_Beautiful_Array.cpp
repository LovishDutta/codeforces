#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(int idx,bool flag,vector<int>& arr,vector<vector<int>>& dp,int& k){
    if(idx>=arr.size()-1) return 0;
    if(dp[idx][flag]!=-1) return dp[idx][flag];
    if(flag){
        return dp[idx][flag]=(arr[idx+1]-arr[idx])/k+recur(idx+2,flag,arr,dp,k);
    }
    else{
        int a=0,b=0;
        if(idx+1<arr.size()) a=(arr[idx+1]-arr[idx])/k+recur(idx+2,flag,arr,dp,k);
        if(idx+1<arr.size()) b=recur(idx+1,true,arr,dp,k);
        return dp[idx][flag]=min(a,b);
    }
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k,cnt=0,ans=0,flag=0;
        cin>>n>>k;
        vector<int> arr(n);
        set<int> st;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(st.find(arr[i])!=st.end()){
                st.erase(arr[i]);
                cnt++;
            }
            else st.insert(arr[i]);
        }
        map<int,vector<int>> mpp;
        for(auto &it: st) mpp[it%k].push_back(it);
        for(auto &it:mpp){
            if(it.second.size()%2==1){
                flag++;
                if(flag==2) break;
                vector<vector<int>> dp(it.second.size()+1,vector<int>(2,-1));
                ans+=recur(0,false,it.second,dp,k);
            }
            else{
                for(int i=0;i<it.second.size()-1;i+=2) ans+=(it.second[i+1]-it.second[i])/k;
            }
        }
        if(flag==2) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}