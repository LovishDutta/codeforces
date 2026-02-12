#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,j,k;
        cin>>n>>j>>k;
        vector<int> arr(n);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            maxi=max(maxi,arr[i]);
        }
        if(k==1){
            if(arr[j-1]==maxi) cout<<"YES";
            else cout<<"NO";
        }
        else cout<<"YES";
        cout<<endl;
    }
}