#include<bits/stdc++.h>
using namespace std;
#define int long long
// bool recur(int idx,int sum,vector<int>& arr){
//     if(idx==arr.size()) return sum==0;
//     bool npi=recur(idx+1,sum,arr),pi=false;
//     if(sum-arr[idx]>=0) pi=recur(idx+1,sum-arr[idx],arr);
//     return pi|npi;
// }
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,cnt=1,a,ele;
        cin>>n>>ele;
        vector<int> arr;
        for(int i=1;i<2*n;i++){
            cin>>a;
            if(a<ele) cnt++;
            else{
                arr.push_back(cnt);
                ele=a;
                cnt=1;
            }
        }
        arr.push_back(cnt);
        int k=arr.size();
        vector<vector<bool>> dp(k+1,vector<bool>(n+1,false));
        dp[k][0]=true;
        for(int idx=k-1;idx>=0;idx--){
            for(int sum=0;sum<=n;sum++){
                dp[idx][sum]=dp[idx+1][sum]|dp[idx][sum];
                if(sum-arr[idx]>=0) dp[idx][sum]=dp[idx][sum]|dp[idx+1][sum-arr[idx]];
            }
        }
        if(dp[0][n]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}