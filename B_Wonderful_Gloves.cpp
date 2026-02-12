#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,k;
        cin>>n;
        cin>>k;
        vector<int> left(n);
        vector<int> right(n);
        int finalans=INT_MAX;
        for(int i=0;i<n;i++){
            cin>>left[i];
        }
        for(int i=0;i<n;i++){
            cin>>right[i];
        }
        long long ans=0;
        vector<int> arr;
        for(int i=0;i<n;i++){
            if(left[i]>right[i]){
                ans+=left[i];
                arr.push_back(right[i]);
            }
            else{
                ans+=right[i];
                arr.push_back(left[i]);
            }
        }
        sort(arr.begin(),arr.end());
        for(int i=arr.size()-1;i>arr.size()-k;i--){
            ans+=arr[i];
        }
        ans+=1;
        cout<<ans<<endl;
}
}