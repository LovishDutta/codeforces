#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        long long steps=0;
        for(int i=0;i<n;i++){
            long long z,o,rz,ro;
            cin>>z>>o>>rz>>ro;
            if(z>rz){
                steps+=z-rz;
            }
            if(o>ro){
                steps+=min(z,rz); 
                steps+=o-ro; 
            }
        }
        cout<<steps<<endl;
    }
}