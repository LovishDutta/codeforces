#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1,k,a,b;
    cin>>tc>>k;  
    vector<int> dp(1e5+1,0);
    dp[0]=1;
    for(int i=1;i<=1e5;i++){
        dp[i]=(dp[i]+dp[i-1])%mod;
        if(i-k>=0) dp[i]=(dp[i]+dp[i-k])%mod;
    }  
    for(int i=1;i<=1e5;i++) dp[i]=(dp[i]+dp[i-1])%mod;
    while(tc--){
        cin>>a>>b;
        cout<<(dp[b]-dp[a-1]+mod)%mod<<endl;
    }
}