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
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]=='0') st.push(0);
            else{
                if(st.size()>0&&st.top()==1) st.pop();
                else st.push(1);
            }
        }
        if(st.size()==0) cout<<0<<endl;
        int ze=0,o=0;
        while(!st.empty()){
            if(st.top()=='0'){
                ze++;
            }
            else{
                o++;
            }
            st.pop();
        }
        if(ze==o) cout<<0<<endl;
        else if(ze>o) cout<<1<<endl;
        else cout<<2<<endl;
    }
}