#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        long long sum=0;
        vector<int> arr(n);
        vector<int> arr2(n);
        for(int i=0;i<n;i++){
            arr[i]=i+1;
            arr2[i]=n-i;
        }
        for(int i=0;i<n;i++){
            if(arr2[i]<arr[i]) break;
            sum+=arr2[i]-arr[i];
        }
        cout<<sum+1<<endl;
    }
}