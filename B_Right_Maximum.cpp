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
        int cnt=0;
        for(int i=0;i<n;i++){
            int ele=arr[i];
            cnt++;
            while(i<n-1&&arr[i+1]<ele) i++;
        }
        cout<<cnt<<endl;
    }
}