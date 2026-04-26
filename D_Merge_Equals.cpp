#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> arr(n);
    set<pair<int,int>> st;
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++){
         cin>>arr[i];
         st.insert({arr[i],i});
    }
    while(!st.empty()){
        auto it=*(st.begin());
        int ele=it.first;
        int idx=it.second;
        st.erase(it);
        pair<int,int> it2={1e15,1};
        it2=*(st.begin());
        int ele2=it2.first;
        int idx2=it2.second;
        if(ele2!=ele){
            ans.push_back({idx,ele});
        }
        else{
            st.erase(it2);
            st.insert({2*ele,idx2});
        }
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) cout<<ans[i].second<<" ";
}