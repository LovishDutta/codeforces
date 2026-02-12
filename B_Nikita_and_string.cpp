#include<bits/stdc++.h>
using namespace std;
int dp[5001][3];
int recur(int i,string& s,int mode){
    if(i==s.size()) return 0;
    if(dp[i][mode]!=-1) return dp[i][mode];
    int pick=0;
    int notpick=recur(i+1,s,mode);
    if(mode<2) notpick=max(notpick,recur(i+1,s,mode+1));
    if((mode==0&&s[i]=='a')||(mode==1&&s[i]=='b')||(mode==2&&s[i]=='a')){
        pick=1+recur(i+1,s,mode);
        if(mode<2) pick=max(pick,1+recur(i+1,s,mode+1));
    }
    return dp[i][mode]=max(pick,notpick);
}
int main(){
    string s;
    cin>>s;
    memset(dp,-1,sizeof(dp));
    cout<<max(recur(0,s,0),recur(0,s,1))<<endl;
}