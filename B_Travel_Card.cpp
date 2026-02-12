#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int recur(int i,vector<int>& arr){
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];
    int a=20+recur(i-1,arr);
    int b=50+recur(lower_bound(arr.begin(),arr.begin()+i,arr[i]-89)-arr.begin()-1,arr);
    int c=120+recur(lower_bound(arr.begin(),arr.begin()+i,arr[i]-1439)-arr.begin()-1,arr);
    return dp[i]=min({a,b,c});
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    dp[0]=20;
    dp[1]=40;
    recur(n-1,arr);
    cout<<dp[0]<<endl;
    for(int i=1;i<n;i++){
        cout<<dp[i]-dp[i-1]<<endl;
    }
}