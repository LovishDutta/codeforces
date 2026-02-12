#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,x,y;
        cin>>n>>x>>y;
        x=abs(x);
        y=abs(y);
        string s;
        cin>>s;
        int four=0,eight=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='4') four++;
            else eight++;
        }
        bool ans=false;
        if(max(x,y)<=eight||2*max(x,y)<=four) ans=true;
        else{
           int square=eight;
           int remX=x-square;
           int remY=y-square;
           if(remX<=0&&remY<=0) ans=true;
           else{
            if(remX<0) remX=0;
            if(remY<0) remY=0;
            if((remX+remY)<=four) ans=true;
           }
        }
        if(ans) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}