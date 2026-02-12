#include<bits/stdc++.h>
using namespace std;
int dp[101][1001];
int recur(int idx,string s,int num){
    if(idx==s.size()){
        if(num%8==0) return num;
        else return -2;
    }
    if(dp[idx][num]!=-1) return dp[idx][num];
    int del=recur(idx+1,s,num);
    int notdel=-1;
    if(num<100) notdel=recur(idx+1,s,(num*10+(s[idx]-'0')));
    return dp[idx][num]=max(del,notdel);
}
int main(){
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
            cout<<"YES"<<endl;
            cout<<0<<endl;
            return 0;
            }
        }
        memset(dp,-1,sizeof(dp));
        int ans=recur(0,s,0);
        if(ans==0||ans==-2) cout<<"NO";
        else{
             cout<<"YES"<<endl;
             cout<<ans<<endl;
        }
}