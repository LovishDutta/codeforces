#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int power(int n, int p){
    int ans = 1;
    int a = n;
    while(p>0){
        if(p%2==1){
            ans*= a;
        }
        a = a*a;
        a%=mod;
        ans%=mod;
        p/=2;
    }
    return ans;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    // vector<vector<int>> dp(n+1,vector<int>(2,0));
    vector<int> dp(k+1,0);
    int hold = power(2,n-1);
    dp[0] = 1;
    dp[1] = n%2==1? hold + 1: hold;
    int h;
    if(n%2==0) h = hold-1;
    else h = hold;
    for(int i=2;i<=k;i++){

        dp[i] = ((dp[i-1]*h)%mod + (n%2==0? (((power(2,n*(i-1))))%mod)%mod:dp[i-1]))%mod;
    }

    cout<<(dp[k]%mod)<<endl;
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}