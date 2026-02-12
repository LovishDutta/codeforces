#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
const int N = 100000;
long long fact[N + 1];
long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = (fact[i - 1] * i) % mod;
}
long long f(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * power(fact[r], mod - 2) % mod * power(fact[n - r], mod - 2) % mod;
}
signed main(){
    int n,t2=0,t3=0;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> a(3);
    for(int i=0;i<n;i+=3){
        a[0]=arr[i];
        a[1]=arr[i+1];
        a[2]=arr[i+2];
        sort(a.begin(),a.end());
        if(a[0]==a[1]&&a[1]!=a[2]) t2++;
        else if(a[0]==a[1]&&a[1]==a[2]) t3++;
    }
    precompute();
    int ans=f(n/3,n/6);
    if(t3>0) ans=(ans* power(3, t3))%mod;
    if(t2>0) ans=(ans* power(2, t2))%mod;
    cout<<ans;
}