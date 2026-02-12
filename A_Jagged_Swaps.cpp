#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int k=0;k<n;k++){
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]){ 
                swap(arr[i],arr[i+1]);
        }
        }
    }
        bool flag=true;
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                flag=false;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}