#include<bits/stdc++.h>
using namespace std;

long long dp[1000001][3][4][3];
long long recur(int idx,int prev1,int prev2,int sub,string& s){
    if(idx==s.size()){
        if(sub==0||sub==1) return 0;
        if(prev2==2){
            return 1;
        }
        return prev2==prev1;
    }
    if(dp[idx][prev1][prev2][sub]!=-1) return dp[idx][prev1][prev2][sub];
    long long ans=0;
    if(sub==0){
        int val=1;
        if(s[idx]=='0') val=0;
        ans+=recur(idx+1,val,prev2,1,s);
        ans+=recur(idx+1,prev1,prev2,0,s);
        ans+=recur(idx+1,val,prev2,2,s);
    }
    else if(sub==1){
        int val=1;
        if(s[idx]=='0') val=0;
        if(val==prev1){
            int newval=!val;
            if(prev2==2||prev2==3){
                 ans+=recur(idx+1,newval,2,1,s);
                 ans+=recur(idx+1,newval,2,2,s);
            }
            else{
                ans+=recur(idx+1,val,2,1,s);
                ans+=recur(idx+1,val,2,2,s);
            }
        }
        else{
            int val=1;
            if(s[idx]=='0') val=0;
            if(prev2==2){
                ans+=recur(idx+1,val,prev1,1,s);
            }
            else ans+=recur(idx+1,val,3,1,s);
        }
    }
    else ans+=recur(idx+1,prev1,prev2,sub,s);
    return dp[idx][prev1][prev2][sub]=ans;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=2;j++){
                for(int k=0;k<=3;k++){
                    for(int l=0;l<=2;l++){
                        dp[i][j][k][l]=-1;
                    }
                }
            }
        }
        cout<<recur(0,2,2,0,s)<<endl;
    }
}