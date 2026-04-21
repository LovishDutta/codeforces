#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,x;
        cin>>n>>x;
        int p=(x+3)/4-(x%4==1);
        int b=(n+3)/4-p;
        int p2=1,b2=1;
        
        if(x<=2) p2=1;
        else if(x%4==3||x%4==0) p2=(x+3)/4+1-(x%4==3);
        else p2=(x+3)/4-(x%4==3);

        if(n<=2) b2=1-p2;
        else if(n%4==3||n%4==0) b2=(n+3)/4+1-p2;
        else b2=(n+3)/4-p2;

        int ans=(((__int128)p*b)%mod+((__int128)p2*b2)%mod)%mod;

    }
}