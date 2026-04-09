#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        long long a,b,k;
        cin>>a>>b>>k;
        long long ans=0;
        long long n=__gcd(a,b);
        if(k>=a/n&&k>=b/n){
            ans=1;
        }
        else ans=2;
        cout<<ans<<endl;
    }
}