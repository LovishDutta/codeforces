#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        vector<int> a(3),b;
        cin>>a[0]>>a[1]>>a[2];
        sort(a.begin(),a.end());
        cout<<min(a[2]-a[0],a[1])<<endl;
    }
}