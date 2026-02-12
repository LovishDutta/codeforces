#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int i=0;i<t;i++){
        int size;
        cin>>size;
        string s;
        cin>>s;
        bool inf=false;
        for(int j=0;j<size-2;j++){
            if(s[j]=='.'&&s[j+1]=='.'&&s[j+2]=='.'){
                inf=true;
                break;
            }
        }
        if(inf) cout<<2<<endl;
        else{
            int cnt=0;
            for(int j=0;j<size;j++){
                if(s[j]=='.') cnt++;
            }
            cout<<cnt<<endl;
        }
}
}