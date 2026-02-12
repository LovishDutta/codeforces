#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,x;
        cin>>n>>x;
        vector<int> arr(n);
        for(int i=0;i<n;i++) arr[i]=(i+1);
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(arr[i]<=x) break;
            ans+=arr[i]-x;
        }
        cout<<ans<<endl;
    }
}