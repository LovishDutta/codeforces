#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5;
const int MOD = 1e9+7;

long long fact[N], invFact[N];
long long power(long long a, long long b){
    long long res = 1;
    while(b){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return res;
}
void precompute(){
    fact[0] = 1;
    for(int i=1;i<N;i++) fact[i] = fact[i-1]*i % MOD;
    invFact[N-1] = power(fact[N-1], MOD-2);
    for(int i=N-2;i>=0;i--) invFact[i] = invFact[i+1]*(i+1)%MOD;
}
long long nCr(int n, int r){
    if(r>n || r<0) return 0;
    return fact[n]*invFact[r]%MOD*invFact[n-r]%MOD;
}
bool good(int& a,int& b,int sum){
        while(sum>0){
            if(!(sum%10==a||sum%10==b)) return false;
            sum=sum/10;
        }     
    return true;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,a,b,ans=0;
    cin>>a>>b>>n;
    precompute();
    for(int i=0;i<=n;i++){
        if(good(a,b,a*i+b*(n-i))){
            ans=(ans+nCr(n,i))%MOD;
        }
    }
    cout<<ans<<endl;
}