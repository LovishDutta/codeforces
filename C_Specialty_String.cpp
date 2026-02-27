#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        stack<char> st;
        for(int i=0;i<n;i++){
            if(!st.empty()&&st.top()==s[i]) st.pop();
            else st.push(s[i]);
        }
        if(!st.empty()) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}