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
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
             cin>>arr[i];
             mpp[arr[i]]=i;
        }
        sort(arr.begin(),arr.end());
        ans[mpp[arr[0]]]=-1;
        ans[mpp[arr[n-1]]]=-1;
        for(int i=1;i<n-1;i++){
            ans[mpp[arr[i]]]=(arr[i+1]+arr[i])/2-(arr[i-1]+arr[i])/2;
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}