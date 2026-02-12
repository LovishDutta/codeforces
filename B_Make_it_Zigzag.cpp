#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
int n;
cin>>n;
vector<int> arr(n);
vector<int> maxi(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
maxi[0]=arr[0];
for(int i=1;i<n;i++){
    maxi[i]=max(arr[i],maxi[i-1]);
}
int ans=0;
for(int i=0;i<n-1;i++){
    if(i%2){
        int a=maxi[i];
        if(a<=arr[i+1]){
            ans+=(arr[i+1]-a)+1;
            arr[i+1]-=(arr[i+1]-a);
            arr[i+1]--;
        }
    }
    else{
        int a=maxi[i+1];
        if(arr[i]>=a){
            ans+=(arr[i]-a)+1;
            arr[i]-=(arr[i]-a);
            arr[i]--;
        } 
    }
}
cout<<ans<<endl;
    }
}