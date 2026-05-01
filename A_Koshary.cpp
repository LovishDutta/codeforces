#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int a,b;
        cin>>a>>b;
        int c=(a%2)+(b%2);
        if(c<=1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}