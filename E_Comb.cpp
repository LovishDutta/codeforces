#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
     ios::sync_with_stdio(false);
     cin.tie(nullptr);
        int n,m;
        cin>>n>>m;
        vector<vector<int> > p(n+1,vector<int>(m+1,0));
        vector<vector<int> > dp(n+1,vector<int>(m+1,-1e12));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>p[i][j];
                p[i][j]+=p[i][j-1];
            }
        }
        for(int i=1;i<=m;i++) dp[0][i]=0;
        for(int i=1;i<=n;i++){
            vector<int> vec(m+2,-1e12);
            if(i%2==0){
                vec[m]=dp[i-1][m];
                for(int j=m-1;j>=1;j--){
                    vec[j]=max(vec[j+1],dp[i-1][j]);
                }
            }
            else{
                for(int j=1;j<=m;j++){
                    vec[j]=max(vec[j-1],dp[i-1][j]);
                }
            }
            for(int j=1;j<=m;j++){
                if(i%2==0) dp[i][j]=vec[j+1]+p[i][j];
                else dp[i][j]=vec[j-1]+p[i][j];
            }
        }
        int ans=-1e12;
        for(int i=1;i<=m;i++) ans=max(ans,dp[n][i]);
        cout<<ans;
}