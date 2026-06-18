#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
int modpow(int a,int b){
    if(b==0) return 1;
    int hf=modpow(a,b/2)%mod;
    if(b%2) return (((hf*hf)%mod)*a)%mod;
    return (hf*hf)%mod;
}
bool isp(int n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 5; i * i <= n; i += 6){
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
vector<int> pf(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m,ans=0;
        cin>>n>>m;
        for(int i=2;i<=m;i++){
            for(int j=2;j<=m;j++){
                if(__gcd(i,j)==1){
                    vector<int> a=pf(i);
                    vector<int> b=pf(j);
                    for(int k=0;k<a.size();k++){
                        for(int l=0;l<b.size();l++){
                            int mult=1;
                            for(int z=l;z<b.size();z++){
                                mult*=b[z];
                                int val=m/(a[k]*mult);
                                ans=(ans+modpow(val,n-2))%mod;
                            }
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}