#include<bits/stdc++.h>
using namespace std;
#define int long long
long long lcm(long long a, long long b){
    return (a / __gcd(a,b)) * b;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int z,ans=0;
        cin>>z;
        for(int i=1;i<=z;i++){
            for(int j=i;j<=z;j+=i){
                if(lcm(i,j)<=z){
                    if(i==j) ans++;
                    else ans+=2;
                }
            }
        }
        cout<<ans<<endl;
    }
}