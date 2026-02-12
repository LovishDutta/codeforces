#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int i=0;i<t;i++){
        int size,n;
        cin>>size;
        cin>>n;
        int arr[size];
        for(int j=0;j<size;j++){
            cin>>arr[j];
        }
        if(size==1||n>=2) cout<<"YES"<<endl;
        else{
            int flag=0;
            for(int k=0;k<size-1;k++){
                if(arr[k]>arr[k+1]){
                    flag=1;
                }
            }
            if(flag) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        } 
    }
    return 0;
}