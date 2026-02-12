#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int main(){
        int n;
        cin>>n;
        vector<int> arr(4,0);
        arr[0]=1;
    for(int i=0;i<n;i++){
        int n1=((arr[0]+arr[2])%mod+arr[3])%mod;
        int n2=((arr[0]+arr[1])%mod+arr[3])%mod;
        int n3=((arr[0]+arr[2])%mod+arr[1])%mod;
        arr[0]=((arr[1]+arr[2])%mod+arr[3])%mod;
        arr[1]=n1;
        arr[2]=n2;
        arr[3]=n3;
    }
    cout<<arr[0]<<endl;
}