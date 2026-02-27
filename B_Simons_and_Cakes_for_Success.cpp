#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int> pf(int n) {
    map<int,int> freq;
    while (n % 2 == 0) {
        freq[2]++;
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            freq[i]++;
            n /= i;
        }
    }
    if (n > 1)
        freq[n]++;
    return freq;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        cin>>n;
        map<int,int> freq=pf(n);
        int ans=1;
        for(auto &it:freq) ans*=(it.first*(((it.second+n-1)/n)));
        cout<<ans<<endl;
    }
}