#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[2001][2][2001];
    long long recur(int idx,bool sign,int t,vector<int>& cost, vector<int>& time){
        int tm=sign?t:-1*t;
        if(idx==cost.size()){
            if(tm<0) return 1e15;
            else return 0;
        }
        if(dp[idx][sign][t]!=-1) return dp[idx][sign][t];
        long long newtm=tm+time[idx],newtm2=tm-1,free=1e15,nf=1e15;
        if(newtm>=0) nf=cost[idx]+recur(idx+1,1,min(newtm,2000LL),cost,time);
        else nf=cost[idx]+recur(idx+1,0,min(-1LL*newtm,2000LL),cost,time);
        if(newtm2>=0) free=recur(idx+1,1,min(newtm2,2000LL),cost,time);
        else free=recur(idx+1,0,min(-1LL*newtm2,2000LL),cost,time);
        return dp[idx][sign][t]=min(free,nf);
    }
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> cost(n),time(n);
    for(int i=0;i<n;i++) cin>>time[i]>>cost[i];
    memset(dp,-1,sizeof(dp));
    cout<<recur(0,0,0,cost,time);
}