#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,flag=1;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.rbegin(),arr.rend());
        for(int i=0;i<n-2;i++){
            if(arr[i]%arr[i+1]!=arr[i+2]){
                flag=0;
                break;
            }
        }
        if(flag) cout<<arr[0]<<" "<<arr[1]<<endl;
        else cout<<-1<<endl;
    }
}