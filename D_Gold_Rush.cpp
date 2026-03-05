#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m,flag=0;
        cin>>n>>m;
        set<int> st;
        set<int> chosen;
        if(n%3==0) st.insert(n);
        if(n==m) flag=1;
        if(m>n){
            cout<<"NO"<<endl;
            continue;
        }
        while(!flag&&st.size()!=0){
            int ele=*(st.rbegin());
            st.erase(ele);
            chosen.insert(ele);
            if((ele)%3==0&&ele>m){
                if(chosen.find(ele/3)==chosen.end()){
                    st.insert(ele/3);
                }
                if(chosen.find(2*ele/3)==chosen.end()){
                   st.insert((2*ele)/3);
                }
                if(ele/3==m||(2*ele)/3==m){
                    flag=1;
                    break;
                }
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}