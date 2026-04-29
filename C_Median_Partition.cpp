#include<bits/stdc++.h>
using namespace std;

int med[5000][5000];
int recur(int idx,vector<int>& dp){
    if(idx==dp.size()) return 0;
    if(dp[idx]!=-1) return dp[idx];
    int ans=-1e8;
    for(int i=idx;i<dp.size();i+=2){
        if(med[idx][i]==med[0][dp.size()-1]&&(idx-i)%2==0) ans=max(ans,1+recur(i+1,dp));
    }
    return dp[idx]=ans;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++){
            priority_queue<int> low;
            priority_queue<int,vector<int>,greater<int>> high;
            for(int j=i;j<n;j++){
                low.push(arr[j]);
                high.push(low.top());
                low.pop();
                if(high.size()>low.size()){
                    low.push(high.top());
                    high.pop();
                }
                med[i][j]=low.top();
            }
        }
        cout<<recur(0,dp)<<endl;
    }
}