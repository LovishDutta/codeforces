#include<bits/stdc++.h>
using namespace std;
#define int long long
long long f(long long n) {
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int x,cnt=0;
        cin>>x;
        for(int i=x;i<=x+10000;i++){
            if(i-f(i)==x) cnt++;
        }
        cout<<cnt<<endl;
    }
}