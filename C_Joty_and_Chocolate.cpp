#include<bits/stdc++.h>
using namespace std;
#define int long long
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}
signed main(){
    int n,a,b,p,q;
    cin>>n>>a>>b>>p>>q;
    if(p>q) cout<<(p*(n/a)+q*(n/b-(n/lcm(a,b))));
    else cout<<(q*(n/b)+p*(n/a-(n/lcm(a,b))));
}