#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        int op=n;
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<n;i++){
           if(arr[i]>0&&sum-(n-i)>=op-1){
            ans=n-i;
            break;
           }
           else{
             op-=arr[i];
             sum-=arr[i];
            }
        }
        cout<<ans<<endl;
    }
}