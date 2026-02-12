#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,w;
        cin>>n>>w;
        cout<<((n/w)*(w-1)+min(w-1,n-(n/w)*w))<<endl;
    }
}