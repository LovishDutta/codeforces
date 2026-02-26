#include<bits/stdc++.h>
using namespace std;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m,maxi=0,a;
        cin>>n>>m;
        vector<int> b(m);
        unordered_set<int> st;
        vector<int> freq(n+m+1,0);
        vector<int> mpp(n+m+1,-1);
        for(int i=0;i<n;i++){
            cin>>a;
            st.insert(a);
        }
        for(int i=0;i<m;i++){
            cin>>a;
            mpp[a]=0;
            freq[a]++;
            maxi=max(maxi,a);
        }
        for(auto &it: st){
            for(int j=it;j<=maxi;j+=it){
                if(mpp[j]>=0) mpp[j]++;
            }
        }
        int notdiv=0,div=0,somediv=0;
        for(int i=0;i<mpp.size();i++){
            if(mpp[i]==0) notdiv+=freq[i];
            else if(mpp[i]==st.size()) div+=freq[i];
            else if(mpp[i]!=-1) somediv+=freq[i];
        }
        if(div+somediv%2>=notdiv+1) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
}