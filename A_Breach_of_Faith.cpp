#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<long long> arr(2*n);
        vector<long long> ans;

        for(int i=0;i<2*n;i++){
            cin>>arr[i];
            
        }
        sort(arr.begin(),arr.end());
        ans.push_back(arr[2*n-1]);
        long long k=0;
        for(int i=0;i<2*n-1;i++){
            if(i%2) k+=arr[i];
            else k-=arr[i];
        }
        ans.push_back(arr[2*n-1]+abs(k));
        for(int i=0;i<2*n-1;i++){
            ans.push_back(arr[i]);
        }
        for(int i=0;i<2*n+1;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}