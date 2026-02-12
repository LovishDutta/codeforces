#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        string s,s2;
        cin>>s;
        int pos,i=0,n=s.size();
        cin>>pos;
        while(n*(i+1)-((i+1)*i)/2<pos) i++;
        if(i>0) pos-=(n*(i)-((i-1)*i)/2);
        stack<char> st;
        for(int j=0;j<s.size();j++){
            if(i==0){
                st.push(s[j]);
                continue;
            }   
                while(!st.empty()&&st.top()>s[j]){
                    st.pop();
                    i--;
                    if(i==0) break;
                }
            st.push(s[j]);
        }
        while(!st.empty()){
             s2.push_back(st.top());
             st.pop();
        }
        reverse(s2.begin(),s2.end());
        cout<<s2[pos-1];
    }
}