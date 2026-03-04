#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,ans=0;
        cin>>n;
        set<int> st;
        for(int i=0;i<=n;i++) st.insert(i);
        while(st.size()>1){
            auto it1=*(st.rbegin());
            st.erase(it1);
            int ele=0;
            for(auto &iter:st){
                if(st.find(it1&iter)!=st.end()&&((it1&iter)!=iter)) ele=iter;
            }
            ans+=it1;
            st.erase(ele);
            st.insert(it1&ele);
        }
        cout<<ans<<endl;
    }
}