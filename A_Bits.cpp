#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int l,r;
        cin>>l>>r;
        int ans=l,f=64;
        for(int i=63;i>=0;i--){
            if(f!=64) ans=(ans|(1LL<<i));
            else if((r&(1LL<<i))>0&&((l&(1LL<<i))==0)) f=i;
        }
        if(__builtin_popcountll(r)>__builtin_popcountll(ans)) cout<<r<<endl;
        else cout<<ans<<endl;
    }
}