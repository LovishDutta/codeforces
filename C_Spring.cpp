#include<bits/stdc++.h>
using namespace std;
#define int long long
long long gcd(long long a,long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}
long long lcm(long long a,long long b){
    return (a/gcd(a,b))*b;
}

signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int a,b,c,m;
        cin>>a>>b>>c>>m;
        int ans=(m/lcm(a,lcm(b,c)))*2+(m/lcm(a,b)-m/lcm(a,lcm(b,c)))*3+(m/lcm(a,c)-m/lcm(a,lcm(b,c)))*3+(m/a-m/lcm(a,b)-m/lcm(a,c)+m/lcm(a,lcm(b,c)))*6;
        cout<<ans<<" ";
        ans=(m/lcm(a,lcm(b,c)))*2+(m/lcm(a,b)-m/lcm(a,lcm(b,c)))*3+(m/lcm(b,c)-m/lcm(a,lcm(b,c)))*3+(m/b-m/lcm(a,b)-m/lcm(b,c)+m/lcm(a,lcm(b,c)))*6;
        cout<<ans<<" ";
        ans=(m/lcm(a,lcm(b,c)))*2+(m/lcm(a,c)-m/lcm(a,lcm(b,c)))*3+(m/lcm(b,c)-m/lcm(a,lcm(b,c)))*3+(m/c-m/lcm(a,c)-m/lcm(b,c)+m/lcm(a,lcm(b,c)))*6;
        cout<<ans<<endl;
    }
}