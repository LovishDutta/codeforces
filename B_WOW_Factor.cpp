#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    string s;
    cin>>s;
    int vcnt=0;
     int ans=0;
     int prev=0;
    int wcnt=0;
    int prevw=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='v') vcnt++;
        else{
            if(vcnt>1) wcnt+=vcnt-1;
            vcnt=0;
        }
        
    }
    if(vcnt>1) wcnt+=vcnt-1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='o'){
            if(prev>1){
                prevw+=prev-1;
            }
            ans+=prevw*(wcnt-prevw);
            prev=0;
        }
        else prev++;
    }
    cout<<ans<<endl;
}