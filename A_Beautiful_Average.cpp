#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            ans=max(ans,arr[i]);
        }
        cout<<ans<<endl;
    }
}