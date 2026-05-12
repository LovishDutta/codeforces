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
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=n-2;i>=0;i--){
            if(arr[i+1]>0) arr[i]+=arr[i+1];
        }
        for(int i=0;i<n;i++) if(arr[i]>0) cnt++;
        cout<<cnt<<endl;
    }
}