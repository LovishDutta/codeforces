#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,maxi=0,ans=0,mex=0,a;
        cin>>n;
        vector<int> arr; 
        set<int> st;
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            cin>>a;
            mpp[a]++;
        }
        auto it=mpp.rbegin();
        arr.push_back((*it).first);
        (*it).second--;
        if((*it).second==0) mpp.erase((*it).first);
        while(mpp.size()!=0){
            vector<int> del;
            for(auto &it:mpp){
                arr.push_back(it.first);
                it.second--;
                if(it.second==0) del.push_back(it.first);
            }
            for(auto &it:del) mpp.erase(it);
        }
        for(int i=0;i<n;i++){
            st.insert(arr[i]);
            while(st.find(mex)!=st.end()) mex++;
            maxi=max(maxi,arr[i]);
            ans+=(maxi+mex);
        }
        cout<<ans<<endl;
    }
}