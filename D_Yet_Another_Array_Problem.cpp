#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios::sync_with_stdio(false); cin.tie(0);

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

 vector<bool> isPrime(N, true);
 vector<int> primes;
void sieve() {
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
           
        }
    }
}
int gcd(const vector<int>& arr) {
    int g = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        g = __gcd(g, arr[i]); 
        if (g == 1) return 1; 
    }
    return g;
}

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
int hcf=gcd(arr);
int ans=2;
for(auto& it:primes){
    if(hcf%it!=0){
        ans=it;
        break;
    }
}
cout<<ans<<endl;
}

int32_t main() {
    fastio;
    int t = 1;
     cin >> t;
     sieve();
    while (t--) solve();
    return 0;
}