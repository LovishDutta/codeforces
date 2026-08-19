#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
long long modpow(long long a, long long b) {
    long long c = 1;
    while (b) {
        if (b & 1) c = c * a % 998244353;
        a = a * a % 998244353;
        b >>= 1;
    }
    return c;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,ans=0;
        cin>>n;
        vector<int> arr(n),freq(n+1,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            freq[arr[i]]++;
        }
        int prod=1;
        for(int i=0;i<=n;i++){
            if(freq[i]==0) break;
            else{
                prod=(prod*(modpow(2LL,freq[i])-1))%mod;
                ans=(ans+prod)%mod;
            }
        }
        prod=1;
        for(int sl=0;sl<n;sl++){
            ans=(ans+(prod*(modpow(2LL,freq[sl+1])-1))%mod)%mod;
            if(freq[sl]==0) break;
            prod=(prod*(modpow(2LL,freq[sl])-1))%mod;
        }
        cout<<ans<<endl;
    }
}