#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k,s,m;
        cin>>n>>k>>s>>m;
        if(n>=4){
            int highest=n;
            if(m==n) highest=n-1;
            if(s<=highest*k) cout<<0<<endl;
            else cout<<k<<endl;
        }
        else if(n==1) cout<<k<<endl;
        else if(n==2){
            if(m==1){
                int ans=0;
                if(s/2>k) ans+=2*(s/2-k);
                cout<<ans<<endl;
            }
            else{
                int ans=;
                if(s/2>k) ans+=(s/2-k);
                cout<<ans<<endl;
            }
        }
    }
}