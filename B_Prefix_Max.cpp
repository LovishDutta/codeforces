#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        int ans=0,maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(arr[i],maxi);
        }
        cout<<maxi*n<<endl;
    }
}