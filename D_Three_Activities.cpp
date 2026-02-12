#include<bits/stdc++.h>
using namespace std;
int dp[100001][2][2][2];
int recur(int i,vector<int>& a,vector<int>& b,vector<int>& c,bool a1,bool b1, bool c1){
    if(i==a.size()) return 0;
    if(dp[i][a1][b1][c1]!=-1) return dp[i][a1][b1][c1];
    int skip=recur(i+1,a,b,c,a1,b1,c1);
    int picka=0,pickb=0,pickc=0;
    if(!a1) picka=a[i]+recur(i+1,a,b,c,true,b1,c1);
    if(!b1) pickb=b[i]+recur(i+1,a,b,c,a1,true,c1);
    if(!c1) pickc=c[i]+recur(i+1,a,b,c,a1,b1,true);
    return dp[i][a1][b1][c1]=max(skip,max(max(picka,pickb),pickc));
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<n;i++) cin>>c[i];
        memset(dp,-1,sizeof(dp));
        cout<<recur(0,a,b,c,false,false,false)<<endl;
    }
}