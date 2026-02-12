#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    set<pair<int,int>> st;
    st.insert({0,0});
    int flag=1,curx=0,cury=0;
    for(int i=0;i<s.size();i++){
        int prevx=curx,prevy=cury;
        if(s[i]=='L') curx--;
        if(s[i]=='R') curx++;
        if(s[i]=='U') cury++;
        if(s[i]=='D') cury--;
        if(st.find({curx,cury})!=st.end()||(!(curx-1==prevx&&cury==prevy)&&st.find({curx-1,cury})!=st.end())||(!(curx==prevx&&cury-1==prevy)&&st.find({curx,cury-1})!=st.end())||(!(curx==prevx&&cury+1==prevy)&&st.find({curx,cury+1})!=st.end())||(!(curx+1==prevx&&cury==prevy)&&st.find({curx+1,cury})!=st.end())){
            flag=0;
            break;
        }
        else st.insert({curx,cury});
    }
    if(flag) cout<<"OK"<<endl;
    else cout<<"BUG"<<endl;
}