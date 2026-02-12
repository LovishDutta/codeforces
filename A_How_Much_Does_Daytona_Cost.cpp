#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n;
        cin>>k;
        int arr[n];
        for(int a=0;a<n;a++){
            cin>>arr[a];
        }
        bool flag=false;
        for(int a=0;a<n;a++){
            if(arr[a]==k){
                flag=true;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}