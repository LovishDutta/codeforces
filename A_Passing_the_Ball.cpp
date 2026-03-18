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
        set<int> st;
        int idx=0;
        st.insert(0);
        for(int i=0;i<n;i++){
            if(s[idx]=='R') idx++;
            else idx--;
            st.insert(idx);
        }
        cout<<st.size()<<endl;
    }
}