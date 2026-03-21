#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,flag=false;
        cin>>n;
        vector<int> arr(2*n);
        multiset<int> ms;
        for(int i=0;i<2*n;i++){
            cin>>arr[i];
            ms.insert(arr[i]);
        }
        sort(arr.begin(),arr.end());
        auto it=prev(ms.end());
        ms.erase(it);
        for(int i=0;i<2*n-1;i++){
            multiset<int> ms2=ms;
            vector<pair<int,int>> ans;
            int cnt=2,x=arr[2*n-1],init=arr[2*n-1]+arr[i];
            auto it=ms2.find(arr[i]);
            ms2.erase(it);
            ans.push_back({arr[i],x});
            while(cnt<2*n&&(!ms2.empty())){
                auto it3=prev(ms2.end());
                int val=*it3;
                ms2.erase(it3);
                auto it2=ms2.find(x-val);
                if(it2!=ms2.end()){
                    x=val;
                    ans.push_back({*it2,x});
                    ms2.erase(it2);
                    cnt+=2;
                }
                else break;
            }
            if(cnt==2*n){
                cout<<"YES"<<endl;
                cout<<init<<endl;
                for(auto &it:ans) cout<<it.first<<" "<<it.second<<endl;
                flag=true;
                break;
            }
        }
        if(!flag) cout<<"NO"<<endl;
    }
}