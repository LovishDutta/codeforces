#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,mult=1;
    cin>>n;
    set<int> st;
    for(int i=1;i<n;i++) st.insert(i);
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int val=i;
            while(val<=n){
                if(st.find(val)!=st.end()) st.erase(val);
                val+=i;
            }
            if(n/i!=i){
            int val2=n/i;
            while(val2<=n){
                if(st.find(val2)!=st.end()) st.erase(val2);
                val2+=n/i;
            }
            }
        }
    }
    for(auto &it:st) mult=(mult*it)%n;
    if(mult!=1){
        auto it=*(st.rbegin());
        st.erase(it);
    }
    cout<<st.size()<<endl;
    for(auto &it:st) cout<<it<<" ";
}