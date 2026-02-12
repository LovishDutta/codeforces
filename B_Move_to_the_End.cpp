#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<int> maxarr(n);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>maxi) maxi=arr[i];
            maxarr[i]=maxi;
        }
        vector<long long> ans(n);
        long long sum=0;
        for(int i=n-1;i>=0;i--){
            ans[n-i-1]=maxarr[i]+sum;
            sum+=arr[i];
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}