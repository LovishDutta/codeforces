#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        long long w,h,a,b,x1,y1,x2,y2;
        cin>>w;
        cin>>h;
        cin>>a;
        cin>>b;
        cin>>x1;
        cin>>y1;
        cin>>x2;
        cin>>y2;
        bool ans=true;
        if(x2>=x1+a&&y2<(y1+b)&&abs(x2-(x1+a))%a!=0) ans=false;
        if(abs(y2-(y1+b))%b!=0&&abs(x2-(x1+a))%a!=0) ans=false;
        if(x2<x1+a&&abs(y2-(y1+b))%b!=0) ans=false;
        if(ans) cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    }
}