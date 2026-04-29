#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a,b,ans=0;
    cin>>a>>b;
    if(a!=b){
        int h=(63 - __builtin_clzll(a^b));
        for(int i=0;i<=h;i++) ans=(ans|(1LL<<i));
    }
    cout<<ans<<endl;
}