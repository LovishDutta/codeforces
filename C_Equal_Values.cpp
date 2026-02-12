#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        long n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        long long mini=LLONG_MAX;
        
        for(int i=0;i<n;i++){
          long long cost;
          int j=i;
          while(j<n&&arr[j]==arr[i]) j++;
          if(i!=0&&i!=n-1) cost=arr[i]*(i)+arr[i]*(n-j);
          else if(i==0) cost=arr[i]*(n-j);
          else{
            cost=arr[i]*(n-1);
          }
          i=j-1;
          mini=min(cost,mini);
        }
        cout<<mini<<endl;
    }
}