#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k,a,flag=1;
    cin>>n>>k;
    vector<vector<int>> arr(n);
    vector<int> deg(n+1,0);
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++){
        cin>>a;
        arr[a].push_back(i+1);
    }
    for(int i=0;i<n-1;i++){
        if(arr[i].size()==0&&arr[i+1].size()!=0){
            cout<<-1<<endl;
            return 0;
        }
    }
    if(arr[0].size()!=1){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<n;i++){
        if(arr[i].size()==0) break;
        int idx=0;
        for(auto &it:arr[i]){
            if(idx>=arr[i-1].size()){
                cout<<-1<<endl;
                return 0;
            }
            if(deg[arr[i-1][idx]]+1<=k){
                deg[arr[i-1][idx]]++;
                deg[it]++;
                ans.push_back({arr[i-1][idx],it});
                if(deg[arr[i-1][idx]]==k) idx++;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto &it:ans) cout<<it.first<<" "<<it.second<<endl;
}