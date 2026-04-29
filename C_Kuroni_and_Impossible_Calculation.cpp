#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,ans=1;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    if(m<n){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans=(ans*abs(arr[i]-arr[j]))%m;
        }
    }
    cout<<ans<<endl;
}