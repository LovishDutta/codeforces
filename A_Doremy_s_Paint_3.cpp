#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int arr[n];
        for(int k=0;k<n;k++){
            cin>>arr[k];
        }
        bool flag=true;
        int a=arr[0],b=-1;
        for(int i=1;i<n;i++){
            if(a!=arr[i]){
                b=arr[i];
                break;
            }
        }
        if(b==-1){
            cout<<"Yes"<<endl;
        }
        else{
        int cnta=1,cntb=0;
        for(int k=1;k<n;k++){
            if(arr[k]==a) cnta++;
            else if(arr[k]==b) cntb++;
           else{
            flag=false;
            break;
           }
        }
        
        if(!(abs(cnta-cntb)==0||abs(cnta-cntb)==1)) flag=false;
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    }
}