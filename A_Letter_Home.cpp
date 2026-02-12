#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,s;
        cin>>n;
        cin>>s;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        int ans=arr[n-1]-arr[0];
        if(abs(s-arr[0])>abs(s-arr[n-1])){
            ans+=abs((s-arr[n-1]));
        }
        else ans+=abs(s-arr[0]);
        cout<<ans<<endl;
    }
}