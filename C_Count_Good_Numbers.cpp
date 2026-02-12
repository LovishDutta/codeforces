#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[20][2][2][3][5][7];
    int recur(string& s,int ind,int tight,int rem1,int rem2,int rem3,int rem4){
        if(ind==s.size()){
            return rem1&&rem2&&rem3&&rem4;
        }
        if(dp[ind][tight][rem1][rem2][rem3][rem4]!=-1) return dp[ind][tight][rem1][rem2][rem3][rem4];
        int limit;
        if(tight==1) limit=s[ind]-'0';
        else limit=9;
        int ans=0;
        for(int i=0;i<=limit;i++){
                int nrem1=(rem1*10+i)%2;
                int nrem2=(rem2*10+i)%3;
                int nrem3=(rem3*10+i)%5;
                int nrem4=(rem4*10+i)%7;
                 ans+=recur(s,ind+1,tight&(i==s[ind]-'0'),nrem1,nrem2,nrem3,nrem4);
                
        }
        return dp[ind][tight][rem1][rem2][rem3][rem4]=ans;
}
int32_t main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        long long l,r;
        cin>>l>>r;
        memset(dp,-1,sizeof(dp));
        string s1=to_string(r);
        string s2=to_string(l-1);
        int ri=recur(s1,0,1,0,0,0,0);
        memset(dp,-1,sizeof(dp));
        int le=recur(s2,0,1,0,0,0,0);
        cout<<ri-le<<endl;
    }
    return 0;
}