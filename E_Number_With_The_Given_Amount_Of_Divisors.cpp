#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> primes(int n) {

    if (n == 0) return {};

    int limit;
    if (n < 6) limit = 15;
    else limit = n * (log(n) + log(log(n))) + 10;

    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }

    vector<int> primes;
    for (int i = 2; i <= limit && primes.size() < n; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
    return primes;
}
vector<long long> pf(long long n) {
    vector<long long> factors;

    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);

    return factors;
}

int recur(int i,int j,vector<int>& factors,vector<int>& prime,vector<vector<int>>& dp){
    if(j==factors.size()) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int p=1;
    int ans=1e18+1;
    for(int k=j;k<factors.size();k++){
        p*=factors[k];
        int mult=1e18+1;
        if(p-1<=18/(log10(prime[i]))){
        mult=1;
        for(int t=0;t<p-1;t++) mult*=prime[i];
    }
    else break;
         int r=mult*recur(i+1,k+1,factors,prime,dp);
        ans=min(ans,r);
    }
    return dp[i][j]=ans;
}

signed main(){
        int n;
        cin>>n;
        vector<int> factors=pf(n);
        vector<int> prime=primes(factors.size());
        reverse(factors.begin(),factors.end());
        vector<vector<int>> dp(prime.size()+1,vector<int>(factors.size()+1,-1));
    cout<<recur(0,0,factors,prime,dp);
}

