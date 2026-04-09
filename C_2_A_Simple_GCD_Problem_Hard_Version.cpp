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
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<n;i++){
            if(i==0){
                int k=__gcd(a[i],a[i+1]),flag=0;
                for(int z=k;z<=b[i];z+=k){
                        if(z!=a[i]&&__gcd(a[i+1],z)==k){
                            flag=1;
                            break;
                        }
                    }
                    if(flag) cnt++;
            }
            else if(i==n-1){
                 int k=__gcd(a[i],a[i-1]),flag=0;
                for(int z=k;z<=b[i];z+=k){
                        if(z!=a[i]&&__gcd(a[i-1],z)==k){
                            flag=1;
                            break;
                        }
                    }
                    if(flag) cnt++;
            }
            else{
                    int gc1=__gcd(a[i-1],a[i]);
                    int gc2=__gcd(a[i+1],a[i]);
                    int k=lcm(gc1,gc2),flag=0;
                    for(int z=k;z<=b[i];z+=k){
                        if(z!=a[i]&&__gcd(a[i-1],z)==gc1&&__gcd(a[i+1],z)==gc2){
                            flag=1;
                            break;
                        }
                    }
                    if(flag) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}