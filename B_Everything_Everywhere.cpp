#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,cnt=0;
        cin>>n;
        vector<int> arr(n);
        vector<int> idx(n+1);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            idx[arr[i]]=i;
        }
        for(int i=0;i<n-1;i++){
            if (abs(arr[i]-arr[i + 1])== __gcd(arr[i],arr[i+1])) cnt++;
        }
        cout<<cnt<<endl;
    }
}