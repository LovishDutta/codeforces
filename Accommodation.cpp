#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int b,g,x,y,n;
        cin>>b>>g>>x>>y>>n;
        if(x+y>n){
            cout<<-1<<endl;
            continue;
        }
        int rem=n-(x+y);
        int ans=max(ceil((double)b/(x+rem)),ceil((double)g/(y+rem)));
        cout<<ans<<endl;
    }
}