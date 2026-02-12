#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int a,x,y;
        cin>>a>>x>>y;
        bool ans=false;
        if(a<min(x,y)) ans=true;
        if(a>max(x,y)) ans=true;
        if(ans) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}