#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;

void f(ll n, unordered_set<ll> &out,int x) {
    if (n <= 0) return;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i != 0) continue;
        ll d1 = i;
        ll d2 = n / i;
        if ((d1 & 1) == 0 && (d1+2)/2>=x) out.insert(d1);
        if (d2 != d1 && (d2 & 1) == 0 && (d2+2)/2>=x) out.insert(d2);
    }
}
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,x;
        cin>>n>>x;
        int ans=0;
       unordered_set<int> st;
        f(n-x,st,x);
        f(n+x-2,st,x);
        ans=st.size();
        cout<<ans<<endl;
    }
}