#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int i=0;i<t;i++){
        int a,b;
        cin>>a;
        cin>>b;
        string x,s;
        cin>>x;
        cin>>s;
        int cnt=0;
        int k=0;
        bool flag=false;
        for(k=0;k<=5;k++){
            if(x.find(s)!=string::npos){
                flag=true;
                break;
            }
            x+=x;
            cnt++;
        }
        if(!flag) cout<<-1<<endl;
        else cout<<cnt<<endl;
}
}