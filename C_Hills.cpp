#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[2][2501][5000];
int recur(int i,bool b1,int k,vector<int>& arr){
   if(k==0) return 0;
   if(i>=arr.size()) return k==0?0:1e12;
   if(dp[b1][k][i]!=-1) return dp[b1][k][i];
   int b=recur(i+2,true,k-1,arr),nb=recur(i+1,false,k,arr);
   b+=(i+1<arr.size()&&arr[i+1]>=arr[i]?arr[i+1]-arr[i]+1:0);
   if(b1) b+=(i-2>=0&&min(arr[i-2]-1,arr[i-1])>=arr[i]?min(arr[i-2]-1,arr[i-1])-arr[i]+1:0);
   else b+=(i-1>=0&&arr[i-1]>=arr[i]?arr[i-1]-arr[i]+1:0);
   return dp[b1][k][i]=min(b,nb);
}
signed main(){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=(n+1)/2;i++){
            cout<<recur(0,false,i,arr)<<" ";
        }
        cout<<endl;

}