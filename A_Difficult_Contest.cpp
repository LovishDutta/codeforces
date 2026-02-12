#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        string s;
        cin>>s;
        string ans="";
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='T') cnt++;
        }
        for(int i=0;i<cnt;i++){
            ans.push_back('T');
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!='T') ans.push_back(s[i]);
        }
        cout<<ans<<endl;
    }
}