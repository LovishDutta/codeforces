#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isprime(int n){
    if(n==1) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0) return false;
    }
    return true;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        cin>>n;
        int i=sqrt(n);
        if(n!=1&&i*i==n&&isprime(i)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}