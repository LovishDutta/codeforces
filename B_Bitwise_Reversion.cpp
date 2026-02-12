#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int x,y,k;
        cin>>k>>y>>x;
        if((x&y)==(y&k)&&(x&k)==(x&y)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}