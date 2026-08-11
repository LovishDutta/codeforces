#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
int dp[200001][3][3];
int recur(int idx,int prev1,int prev2,string& s){
    if(idx==s.size()) return 1;
    if(dp[idx][prev1][prev2]!=-1) return dp[idx][prev1][prev2];
    int ans=0;
    if(s[idx]=='1'){
        if(prev2==1) return 0;
        ans=(ans+recur(idx+1,1,prev1,s))%mod;
    }
    else if(s[idx]=='0'){
        if(prev2==0) return 0;
        ans=(ans+recur(idx+1,0,prev1,s))%mod;
    }
    else{
        if(prev1==2||prev2==2){
            ans=(ans+recur(idx+1,1,prev1,s))%mod;
            ans=(ans+recur(idx+1,0,prev1,s))%mod;
        }
        else if(prev1+prev2==0){
            ans=(ans+recur(idx+1,1,prev1,s))%mod;
        }
        else if(prev1+prev2==1){
            if(prev1==1) ans=(ans+recur(idx+1,1,prev1,s))%mod;
            else ans=(ans+recur(idx+1,0,prev1,s))%mod;
        }
        else{
            ans=(ans+recur(idx+1,0,prev1,s))%mod;
        }
    }
    return dp[idx][prev1][prev2]=ans;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<=n;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        cout<<recur(0,2,2,s)<<endl;
    }
}