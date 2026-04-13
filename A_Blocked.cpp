#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,flag=1;
        cin>>n;
        vector<int> a(n);
        set<int> st;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(st.find(a[i])!=st.end()) flag=0;
            st.insert(a[i]);
        }
        if(!flag){
            cout<<-1<<endl;
            continue;
        }
        sort(a.rbegin(),a.rend());
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
}