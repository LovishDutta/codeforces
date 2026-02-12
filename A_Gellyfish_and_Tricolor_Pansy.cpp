#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int a,b,c,d;
        cin>>a;
        cin>>b;
        cin>>c;
        cin>>d;
        
        if(min(a,c)>=min(b,d)) cout<<"Gellyfish";
        else cout<<"Flower";
        cout<<endl;
    }
}