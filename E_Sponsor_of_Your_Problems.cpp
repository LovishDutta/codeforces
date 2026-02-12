#include<bits/stdc++.h>
using namespace std;
    int dp[10][2][46][46];
    bool isprime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
    int recur(string& s,int ind,int tight,int evensum,int oddsum){
        if(ind==s.size()){
        if(ind%2==0) return isprime(evensum-oddsum);
        else return isprime(oddsum-evensum);
    }   
        if(dp[ind][tight][evensum][oddsum]!=-1) return dp[ind][tight][evensum][oddsum];
        int limit=(tight==1?s[ind]-'0':9);
        int ans=0;
        for(int i=0;i<=limit;i++){
             if(ind%2==0) ans+=recur(s,ind+1,tight&(i==s[ind]-'0'),evensum+i,oddsum);
             else ans+=recur(s,ind+1,tight&(i==s[ind]-'0'),evensum,oddsum+i);
        }
        return dp[ind][tight][evensum][oddsum]=ans;
    }
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        long long l,r;
        cin>>l>>r;
        string rs=to_string(r);
        string ls=to_string(l-1);
        memset(dp,-1,sizeof(dp));
        int ri=recur(rs,0,1,0,0);
        memset(dp,-1,sizeof(dp));
        int li=recur(ls,0,1,0,0);
        cout<<ri-li<<endl;
    }
}