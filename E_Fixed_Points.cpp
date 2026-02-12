#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,k,ans=1e8,cnt=0;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            if(arr[i-1]==i) cnt++;
            dp[i][0]=cnt;
        }
        for(int i=1;i<=n;i++){
            for(int del=1;del<=n;del++){
                dp[i][del]=max(dp[i-1][del-1],dp[i-1][del]+(arr[i-1]==i-del));
            }
        }
        for(int i=0;i<=n;i++) if(dp[n][i]>=k) ans=min(ans,i);
        cout<<(ans==1e8?-1:ans)<<endl;
    }
}