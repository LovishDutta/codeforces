#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        string ans="";
        if(n%4==0) ans="Bob";
        else ans="Alice";
        cout<<ans<<endl;
    }
}