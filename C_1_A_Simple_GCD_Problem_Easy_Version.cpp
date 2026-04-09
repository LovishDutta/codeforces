#include<bits/stdc++.h>
using namespace std;
#define int long long
long long lcm(long long a, long long b){
    return (a / __gcd(a,b)) * b;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,cnt=0;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++){
            if(i==0){
                if(__gcd(a[i],a[i+1])<a[i]) cnt++;
            }
            else if(i==n-1){
                if(__gcd(a[i-1],a[i])<a[i]) cnt++;
            }
            else{
                    int gc1=__gcd(a[i-1],a[i]);
                    int gc2=__gcd(a[i+1],a[i]);
                    int m=lcm(gc1,gc2);
                if(m>=1&&m<a[i]&&__gcd(a[i-1],m)==gc1 &&__gcd(m,a[i+1])==gc2) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}