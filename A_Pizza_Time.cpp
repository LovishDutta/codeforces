#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        int ans=0;
        while(n>2){
            ans+=n/3;
            n=n-2*(n/3);
        }
        cout<<ans<<endl;
    }
}