#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int l,a,b;
        cin>>l>>a>>b;
        int ans=a;
        for(int i=0;i<3*l;i++){
            ans=max(ans,(a+i*b)%l);
        }
        cout<<ans<<endl;
    }
}