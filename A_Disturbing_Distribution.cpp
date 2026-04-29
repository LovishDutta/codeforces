#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod= 676767677;
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,sum=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
             cin>>arr[i];
             if(arr[i]!=1) sum=(sum+arr[i])%mod;
        }
        if(arr[n-1]==1) sum++;
        cout<<sum<<endl;
    }
}