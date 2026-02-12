#include<bits/stdc++.h>
using namespace std;
bool isnest(string& s){
    int n=s.size()/2;
    for(int i=0;i<n;i++){
        if(s[i]!='(') return false;
    }
    return true;
}
bool isValid(string& s) {
       stack<char> st;
       for(int i=0;i<s.size();i++){
        if(s[i]=='['||s[i]=='{'||s[i]=='(') st.push(s[i]);
        else{
            if(st.empty()) return false;
            if(st.top()=='['&&s[i]==']') st.pop();
            else if(st.top()=='('&&s[i]==')') st.pop();
            else if(st.top()=='{'&&s[i]=='}') st.pop();
            else return false;
        }
       }
       return st.empty();
    }
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        string s;
        cin>>s;
        if(isnest(s)) cout<<"NO"<<endl;
        else{
        string st="";
        for(int i=1;i<s.size()-1;i++){
            st+=s[i];
        }
        if(isValid(st)) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    }
}