#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
// req 1-->1 2-->0
int dp[200001][3][3][3];
int recur(int idx,int prev,int req,int propo,string& s){
    if(idx==s.size()) return req==0&&propo!=0;
    if(dp[idx][prev][req][propo]!=-1) return dp[idx][prev][req][propo];
    int ans=0;
    if(s[idx]=='1'){
        if(req==0){
            ans=(ans+recur(idx+1,1,0,1,s))%mod;
            if(propo==0){
                ans=(ans+recur(idx+1,0,0,0,s))%mod;
                ans=(ans+recur(idx+1,0,0,1,s))%mod;
            }
            else{
                ans=(ans+recur(idx+1,0,2,2,s))%mod;
            }
        }
        else if(req==1){
            ans=(ans+recur(idx+1,1,0,1,s))%mod;
            ans=(ans+recur(idx+1,0,2,2,s))%mod;
        }
        else{
            ans=(ans+recur(idx+1,0,2,2,s))%mod;
        }
    }
    else{
        if(req==0){
            ans=(ans+recur(idx+1,0,0,0,s))%mod;
            if(propo==1){
                ans=(ans+recur(idx+1,1,0,1,s))%mod;
                ans=(ans+recur(idx+1,0,0,1,s))%mod;
            }
            else{
                ans=(ans+recur(idx+1,1,1,2,s))%mod;
            }
        }
        else if(req==1){
            ans=(ans+recur(idx+1,1,1,2,s))%mod;
        }
        else{
            ans=(ans+recur(idx+1,1,1,2,s))%mod;
            ans=(ans+recur(idx+1,0,0,0,s))%mod;
        }
    }
    // if(s[idx]=='1'){
    //    if(req==0){
    //     ans=(ans+recur(idx+1,1,0,s))%mod;
    //     if(prev!=0) ans=(ans+recur(idx+1,0,2,s))%mod;
    //     else ans=(ans+recur(idx+1,0,0,s))%mod;
    //    }
    //    else if(req==1){
    //     ans=(ans+recur(idx+1,1,0,s))%mod;
    //     ans=(ans+recur(idx+1,0,2,s))%mod;
    //    }
    //    else{
    //     ans=(ans+recur(idx+1,0,2,s))%mod;
    //    }
    // }
    // else{
    //     if(req==0){
    //     ans=(ans+recur(idx+1,0,0,s))%mod;
    //     if(prev!=1) ans=(ans+recur(idx+1,1,1,s))%mod;
    //     else ans=(ans+recur(idx+1,1,0,s))%mod;
    //    }
    //    else if(req==1){
    //     ans=(ans+recur(idx+1,1,1,s))%mod;
    //    }
    //    else{
    //     ans=(ans+recur(idx+1,0,0,s))%mod;
    //     ans=(ans+recur(idx+1,1,1,s))%mod;
    //    }
    // }
    return dp[idx][prev][req][propo]=ans;
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
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        dp[i][j][k][l]=-1;
                    }
                }
            }
        }
        cout<<recur(0,2,0,2,s)<<endl;
    }
}