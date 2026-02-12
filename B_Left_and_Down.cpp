#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        long long a,b,k;
        cin>>a>>b>>k;
        long long ans=0;
        long long n=gcd(a,b);
        if(k>=a/n&&k>=b/n){
            ans=1;
        }
        else ans=2;
        cout<<ans<<endl;
    }
}