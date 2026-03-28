#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        if(n==1){
             cout<<1<<endl;
             continue;
        }
        for(int i=0;i<n;i++) cout<<2<<" ";
        cout<<endl;
    }
}