#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
pair<int,int> dp[1024][20][2][2];
pair<int,int> recur(int picked,int ind,int tight,bool started,int& k,string& s,vector<int>& ten){
        int ans=0;
        if(ind==s.size()){
            if (started) return {1, 0};
            else return {0, 0};
        }
        if(!(dp[picked][ind][tight][started].first==-1&&dp[picked][ind][tight][started].second==-1)) return dp[picked][ind][tight][started];
        int limit;
        if(tight==1) limit=s[ind]-'0';
        else limit=9;
        int cnt=0;
        for(int i=0;i<=limit;i++){
            bool newstart=started|(i!=0);
            int ct=0;
            if(newstart){
                if((picked&(1<<i))){
                    auto it=recur(picked,ind+1,tight&(i==s[ind]-'0'),newstart,k,s,ten);
                    ct+=it.first;
                    int x = (ten[s.size()-1-ind] * i) % mod;
                    int y = ct % mod;
                    ans = (ans + x * y % mod + it.second) % mod;
            }
                else if(__builtin_popcount(picked)+1<=k+1){
                    auto it=recur(picked|(1<<i),ind+1,tight&(i==s[ind]-'0'),newstart,k,s,ten);
                    ct+=it.first;
                    int x = (ten[s.size()-1-ind] * i) % mod;
                    int y = ct % mod;
                    ans = (ans + x * y % mod + it.second) % mod;
                }
            }
            else{
                auto it=recur(picked,ind+1,tight&(i==s[ind]-'0'),newstart,k,s,ten);
                ct+=it.first;
                int x = (ten[s.size()-1-ind] * i) % mod;
                int y = ct % mod;
                ans = (ans + x * y % mod + it.second) % mod;
            }
            cnt+=ct;
        }
        return dp[picked][ind][tight][started]={cnt,ans};
    }
signed main(){
    int l,r,k;
    cin>>l>>r>>k;
    l--;
    k--;
    vector<int> ten;
    ten.push_back(1);
    for(int i=0;i<18;i++) ten.push_back((ten[ten.size()-1]*10)%mod);
    string ri=to_string(r);
    string le=to_string(l);
    memset(dp,-1LL,sizeof(dp));
    int a=recur(0,0,1,0,k,ri,ten).second;
    memset(dp,-1LL,sizeof(dp));
    int b=recur(0,0,1,0,k,le,ten).second;
    cout<<(a - b + mod) % mod <<endl;
}