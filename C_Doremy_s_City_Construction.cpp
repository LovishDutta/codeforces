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
        sort(arr.begin(),arr.end());
        int cnt=n/2;
        for(int i=0;i<n;i++){
            while(i+1<n&&arr[i+1]==arr[i]) i++;
            cnt=max(cnt,(i+1)*(n-1-i));
        }
        cout<<cnt<<endl;
    }
}