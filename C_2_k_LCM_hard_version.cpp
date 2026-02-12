#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,k;
        cin>>n>>k;
        while(k>3){
            cout<<1<<" ";
            k--;
            n--;
        }
            if(n%2){
            cout<<(n-1)/2<<" "<<(n-1)/2<<" "<<1<<endl;
        }
        else{
            if(n%4==0) cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;
            else cout<<(n-2)/2<<" "<<(n-2)/2<<" "<<2<<endl;
        }
    }
}