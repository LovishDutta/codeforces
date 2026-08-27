#include<bits/stdc++.h>
using namespace std;
#define int long long
static bool comp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    return (a.first.second*b.first.first)>(b.first.second*a.first.first);
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,hcnt=0,ans=0;
    cin>>n;
    vector<string> arr(n);
    vector<pair<pair<int,int>,int>> str;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        int s=0,h=0;
        for(int j=0;j<arr[i].size();j++){
            if(arr[i][j]=='s') s++;
            else h++;
        }
        str.push_back({{s,h},i});
    }
    sort(str.begin(),str.end(),comp);
    for(int i=0;i<str.size();i++){
        for(int j=arr[str[i].second].size()-1;j>=0;j--){
            if(arr[str[i].second][j]=='h') hcnt++;
            else ans+=hcnt;
        }
    }
    cout<<ans<<endl;
}