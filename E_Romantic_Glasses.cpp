#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
       int n;
       cin>>n;
       vector<int> arr(n);
       for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i%2==1) arr[i]*=-1;
       }
       map<long long,int> mpp;
       bool ans=false;
       long long sum=0;
       mpp[0]=-1;
       for(int i=0;i<n;i++){
        sum+=arr[i];
        if(mpp.find(sum)!=mpp.end()){
            ans=true;
            break;
        }
       mpp[sum]=i;
       }
       if(ans) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }
}