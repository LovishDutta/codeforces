#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int a,b,c,cnt=0,cnt2=0,c1;
        cin>>a>>b>>c;
        c1=c;
        while(true){
            if(a==b) break;
            cnt++;
            if(__gcd(a,c)==__gcd(b,c)){
                break;
            }
            c++;
        }
        c=c1;
        while(true){
            if(a==b) break;
            cnt2++;
            if(__gcd(a,c)==__gcd(b,c)){
               // cout<<cnt2<<" "<<a<<" "<<__gcd(b,c)<<endl;
                break;
            }
            else{
                a=__gcd(a,c);
                b=__gcd(b,c);
            }
            cnt2++;
            c++;
        }
        cout<<min(cnt,cnt2)<<endl;
    }
}