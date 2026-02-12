#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
             cin>>arr[i];
             if(k%2) cout<<(arr[i]%2==0?arr[i]:(arr[i]+k))<<" ";
        }
        if(k==2){
            for(int i=0;i<n;i++){
             if(arr[i]%3==0) cout<<arr[i]<<" ";
             else if(arr[i]%3==1) cout<<arr[i]+2<<" ";
             else cout<<(arr[i]+4)<<" ";
        }
        }
        if(k%2==1||k==2){
            cout<<endl;
            continue;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=arr[i]+k*((k-1)-(arr[i])%(k-1));
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}