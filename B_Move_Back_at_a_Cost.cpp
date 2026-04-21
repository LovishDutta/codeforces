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
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<int> ans;
        multiset<int> rem;
        for(int i=0;i<n;i++){
            while(ans.size()>0&&ans[ans.size()-1]>arr[i]){
                rem.insert(ans[ans.size()-1]+1);
                ans.pop_back();
            }
            ans.push_back(arr[i]);
        }
        while(ans.size()>0&&rem.size()>0&&ans[ans.size()-1]>*(rem.begin())){
                rem.insert(ans[ans.size()-1]+1);
                ans.pop_back();
            }
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        for(auto &it:rem) cout<<it<<" ";
        cout<<endl;
    }
}