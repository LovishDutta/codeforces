#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int i=0;i<t;i++){
        int n,x;
        cin>>n;
        cin>>x;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        int ans=max((arr[0]-0),2*(x-arr[n-1]));
        for(int k=0;k<n-1;k++){
            ans=max(ans,arr[k+1]-arr[k]);
        }
        cout<<ans<<endl;
    }
}