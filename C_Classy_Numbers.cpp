#include<bits/stdc++.h>
using namespace std;
int dp[19][2][19];
    int recur(string& s,int ind,int tight,int nonzero){
        if(ind==s.size()) return nonzero<=3;
        if(dp[ind][tight][nonzero]!=-1) return dp[ind][tight][nonzero];
        int limit;
        if(tight==1) limit=s[ind]-'0';
        else limit=9;
        int ans=0;
        for(int i=0;i<=limit;i++){
            ans+=recur(s,ind+1,tight&(i==s[ind]-'0'),(i==0?nonzero:nonzero+1));
        }
        return dp[ind][tight][nonzero]=ans;
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        long long l,r;
        cin>>l>>r;
        memset(dp,-1,sizeof(dp));
        string s1=to_string(r);
        string s2=to_string(l-1);
        int ri=recur(s1,0,1,0);
        memset(dp,-1,sizeof(dp));
        int le=recur(s2,0,1,0);
        cout<<ri-le<<endl;
    }
}