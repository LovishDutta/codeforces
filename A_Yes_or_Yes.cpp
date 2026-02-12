#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        string s;
        cin>>s;
        int y=0;
        bool f=true;
        for(int i=0;i<s.size();i++){
            if(s[i]=='Y') y++;
            if(y>=2){
                f=false;
                break;
            }
        }
        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}