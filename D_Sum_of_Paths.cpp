#include<bits/stdc++.h>
using namespace std;
int dp[10][10];
int recur(int i,int j,vector<int>& arr,int k){
    if(i==arr.size()||i<0) return 0;
    if(j==f0) return dp[i][j]=1;
    if(dp[i][j]!=-1) return dp[i][j];
    int cnt=0;
    cnt+=recur(i-1,j-1,arr,k);
    cnt+=recur(i+1,j-1,arr,k);
    if(j==k){
        cnt+=recur(i+1,j,arr,k);
    }
    return dp[i][j]=cnt;
}
int main(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> arr(n);
    vector<pair<int,int>> query(q);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<q;i++) cin>>query[i].first>>query[i].second;
    memset(dp,-1,sizeof(dp));
    recur(0,k,arr,k);
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

}