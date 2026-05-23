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
        set<int> st;
        for(int i=2;i<=2*n;i++) st.insert(i);
        cout<<1<<" ";
        int prev=1;
        for(int i=1;i<n;i++){
            int ele=*(st.begin());
            if(st.find(ele+prev)!=st.end()) st.erase(ele+prev);
            cout<<ele<<" ";
            st.erase(ele);
            prev=ele;
        }
        cout<<endl;
    }
}