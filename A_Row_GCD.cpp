#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,gc=0,a;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i>=1) gc=__gcd(gc,abs(arr[i]-arr[i-1]));
    }
    for(int i=0;i<m;i++){
        cin>>a;
        cout<<__gcd(gc,arr[n-1]+a)<<" ";
    }
}