#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,odd=0,a,eve=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a%2) odd++;
            else eve++;
        }
        if(eve==odd) cout<<(odd+eve)<<endl;
        else cout<<(min(odd,eve)*2+1)<<endl;
    }
}