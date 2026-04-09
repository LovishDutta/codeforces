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
        vector<int> a(n),ans(n);
        set<int> st;
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            st.insert(i+1);
            cin>>a[i];
            ans[i]=n+1-a[i];
            mpp[ans[i]]=i;
            if(i%2&&a[i]==1) flag=0; 
        }
        if(flag){
            for(int i=1;i<n-1;i+=2){
                auto it = st.upper_bound(ans[i]);
                if(it == st.end()) continue;
                int ele = *it;
                int idx=mpp[ele];
                swap(ans[i],ans[idx]);
                st.erase(ele);
                mpp[ans[i]]=i;
                mpp[ans[idx]]=idx;
            }
        }
        else{
            for(int i=2;i<n-1;i+=2){
                auto it = st.upper_bound(ans[i]);
                if(it == st.end()) continue;
                int ele = *it;
                int idx=mpp[ele];
                swap(ans[i],ans[idx]);
                st.erase(ele);
                mpp[ans[i]]=i;
                mpp[ans[idx]]=idx;
            }
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}