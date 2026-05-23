#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,a,b;
        cin>>n>>a>>b;
        if(3*a<=b){
            cout<<n*a<<endl;
            continue;
        }
        else{
            int ans=0;
            ans+=(n/3)*b;
            int left=n%3;
            if(left==2){
            if(2*a<=b){
           ans+=2*a;
            }
            else ans+=b;
            }
            else if(left==1){
            if(a<=b){
           ans+=a;
            }
            else ans+=b;
            }
            cout<<ans<<endl;
            }
        }
}