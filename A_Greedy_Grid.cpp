#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,m;
        cin>>n>>m;
        string ans="";
        if(n<2||m<2||(n==2&&m==2)) ans="NO";
        else ans="YES";
        cout<<ans<<endl;
    }
}