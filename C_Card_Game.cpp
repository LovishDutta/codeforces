#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool one=false,last=false;

        if(s[0]=='A') one=true;
        if(s[n-1]=='A') last=true;
        if(one&&last) cout<<"Alice"<<endl;
        else if(!one&&!last) cout<<"Bob"<<endl;
        else if(one&&!last){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(s[i]=='B') cnt++;
                if(cnt>1) break;
            }
            if(cnt>1) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
        else if(!one&&last){
            if(n==2){
                if(s[n-1]=='B') cout<<"Alice"<<endl;
                else cout<<"Bob"<<endl;
            } 
            else{
            if(s[n-2]=='A') cout<<"Alice"<<endl;
            else cout<<"Bob"<<endl;
            }
        }

    }
}