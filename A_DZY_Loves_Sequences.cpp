#include<bits/stdc++.h>
using namespace std;
int dp[100002][2][3][2];
int recur(int i,bool changed,int flag,bool started,vector<int>& arr){
    if(i==arr.size()) return 0;
    if(dp[i][changed][flag][started]!=-1) return dp[i][changed][flag][started];
    int ans=0;
    if(!started){
        int ns=recur(i+1,0,0,0,arr);
        int s=1+max(recur(i+1,0,0,1,arr),recur(i+1,1,2,1,arr));
        ans=max(s,ns);
    }
    else{
        int nc=0,c=0,prev=0; 
        if(!flag) prev=arr[i-1];
        else if(flag==2) prev=-1;
        else prev=arr[i-2]+1;
        if(arr[i]>prev){
        nc=1+recur(i+1,changed,0,true,arr);
        if(!changed) c=1+recur(i+1,true,1,true,arr);
        }
        else if(arr[i]<=prev){
            if(!changed) c=1+recur(i+1,true,1,true,arr);
        }
        ans=max(nc,c);
    }
    return dp[i][changed][flag][started]=ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<recur(0,0,0,0,arr);   
}