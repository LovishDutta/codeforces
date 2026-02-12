#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int c;
            cin>>c;
            arr[i]=c;
        }
        ans[0]=0;
        int mini=arr[0];
        int maxi=arr[0];
        // for(int i=1;i<n;i++){
        //     mini=min(mini,arr[i]);
        //     maxi=max(maxi,arr[i]);
        //     ans[i]=max(mini,maxi%mini);
        // }
        for(int i=1;i<n;i++){
            mini=min(mini,arr[i]);
            maxi=max(maxi,arr[i]);
            for(int j=0;j<i;j++){

            }
        }
         for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}