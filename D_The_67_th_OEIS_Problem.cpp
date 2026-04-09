#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> pf(int n) {
    if (n == 1) return {2};

    int limit = n * (log(n) + log(log(n))) + 10;
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= limit && primes.size() < n; i++) {
        if (isPrime[i]) primes.push_back(i);
    }

    return primes;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        cin>>n;
        vector<int> p=pf(n+1);
        for(int i=0;i<n;i++) cout<<p[i]*p[i+1]<<" ";
        cout<<endl;
    }
}