#include<bits/stdc++.h>
using namespace std;
#define int long long
int funct(vector<int>& arr1,vector<int>& arr2,int idx){
    int left1=0,right1=0,left2=0,right2=0;
    for(int i=0;i<idx;i++){
        if(!(arr1[i]<arr1[idx]||arr2[i]<arr1[idx])) left1++;
        if(!(arr1[i]<arr2[idx]||arr2[i]<arr2[idx])) left2++;
    }
    for(int i=idx+1;i<arr1.size();i++){
        if(!(arr1[i]>arr1[idx]||arr2[i]>arr1[idx])) right1++;
        if(!(arr1[i]>arr2[idx]||arr2[i]>arr2[idx])) right2++;
    }
    return min(left1+right1,left2+right2);
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,ans=0;
        cin>>n;
        vector<int> arr(n);
        vector<int> arr2(n);
        for(int i=0;i<n;i++){
             cin>>arr[i];
             arr2[i]=2*n-arr[i];
        }
        for(int i=0;i<n;i++) ans+=funct(arr,arr2,i);
        cout<<ans<<endl;
    }
}