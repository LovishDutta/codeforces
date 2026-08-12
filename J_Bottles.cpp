#include<bits/stdc++.h>
using namespace std;
//#define int long long
pair<int,int> dp[101][200001];
pair<int,int> mini(pair<int,int> a,pair<int,int> b){
    if(a.first<b.first) return a;
    if(a.first>b.first) return b;
    if(a.second<b.second) return a;
    return b;
}
pair<int,int> recur(int idx,int sum,vector<int>& a,vector<int>& b){
    if(idx==a.size()){
        if(sum>=1e5) return {0,0};
        return {1e9,1e9};
    }
    if(dp[idx][sum].first!=-1) return dp[idx][sum];
    pair<int,int> ans={1e9,1e9};
    pair<int,int> pi=recur(idx+1,sum+(b[idx]-a[idx]),a,b);
    pair<int,int> npi=recur(idx+1,sum-a[idx],a,b);
    ans=mini(ans,{pi.first+1,pi.second});
    ans=mini(ans,{npi.first,npi.second+a[idx]});
    return dp[idx][sum]=ans;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<101;i++){
        for(int j=0;j<200001;j++){
            dp[i][j].first=-1;
            dp[i][j].second=-1;
        }
    }
    pair<int,int> ans=recur(0,1e5,a,b);
    cout<<ans.first<<" "<<ans.second;
}