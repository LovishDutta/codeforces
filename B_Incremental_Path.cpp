#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        set<int> st;
        for(int i=0;i<m;i++){
            int a;
            cin>>a;
            st.insert(a);
        }
        int pos=1;
        if(s[0]=='A'){
            pos++;
            if(st.find(pos)==st.end()) st.insert(pos);
        }
        else {
            pos++;
               while(st.find(pos)!=st.end()){
                pos++;
               }
               st.insert(pos);
        }
        int prevpos=1;
        for(int i=1;i<n;i++){
            int pos=prevpos;
            if(s[i-1]=='A'){
            pos++;
           // if(st.find(pos)==st.end()) st.insert(pos);
        }
        else {
             pos++;
               while(st.find(pos)!=st.end()){
                pos++;
               }
             //  st.insert(pos);
        }
        prevpos=pos;
            if(s[i]=='A'){
                pos++;
                if(st.find(pos)==st.end()) st.insert(pos);
            }
            else {
               pos++;
               while(st.find(pos)!=st.end()){
                pos++;
               }
               st.insert(pos);
            }
        }
         cout<<st.size()<<endl;
         for(auto &it:st) cout<<it<<" ";
         cout<<endl;
    }
}