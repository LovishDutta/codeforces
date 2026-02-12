#include<bits/stdc++.h>
using namespace std;
int main(){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<vector<vector<bool>>> dp(n+2,vector<vector<bool>>(k+1,vector<bool>(k+1,false)));
        dp[0][0][0]=true;
        set<int> st;
        for(int i=1;i<=n;i++){
            for(int sum1=0;sum1<=k;sum1++){
                for(int sum2=0;sum2<=k;sum2++){
                    dp[i][sum1][sum2]=dp[i-1][sum1][sum2];
                    if(sum1>=arr[i-1]) dp[i][sum1][sum2]=(dp[i-1][sum1-arr[i-1]][sum2]|dp[i][sum1][sum2]);
                    if(sum1>=arr[i-1]&&sum2>=arr[i-1]) dp[i][sum1][sum2]=(dp[i-1][sum1-arr[i-1]][sum2-arr[i-1]]|dp[i][sum1][sum2]);
                    if(sum1==k&&dp[i][sum1][sum2]) st.insert(sum2);
                }
            }
        }
        cout<<st.size()<<endl;
        for(auto& it:st) cout<<it<<" ";
        cout<<endl;
}