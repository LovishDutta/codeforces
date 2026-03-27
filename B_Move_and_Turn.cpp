#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    if(n%2) cout<<((n+1)/2)*(3+n);
    else if(n%4==0) cout<<(1+((n-4)/4+1)*(n+4));
    else cout<<((n-2)/4+1)*(2+n);
}