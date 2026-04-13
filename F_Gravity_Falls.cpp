#include<bits/stdc++.h>
using namespace std;
#define int long long
static bool comp(vector<int>& a,vector<int>& b){
    return a.size()<b.size();
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m,a=0;
        cin>>n;
        vector<vector<int>> arr;
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            cin>>m;
            vector<int> vec(m);
            for(int i=0;i<m;i++) cin>>vec[i];
            arr.push_back(vec);
            a=max(a,m);            
        }
        sort(arr.begin(),arr.end(),comp);
        for(int i=0;i<n;i++) temp.push_back({arr[i][0],i});
        vector<int> ans(a);
        for(int i=0;i<a;i++){
            vector<pair<int,int>> vec;
            sort(temp.begin(),temp.end());
            ans[i]=temp[0].first;
            bool flag=false;
            for(int j=0;j<temp.size()&&temp[j].first==temp[0].first;j++){
                if(!(i+1<arr[temp[j].second].size())){
                    flag=true;
                    break;
                }
            }
            if(!flag){
            for(int j=0;j<temp.size()&&temp[j].first==temp[0].first;j++){
                if(i+1<arr[temp[j].second].size()) vec.push_back({arr[temp[j].second][i+1],temp[j].second});
            }
            }
            if(flag){
                int j=n-1;
                while(j>=0&&arr[j].size()>i+1){
                    vec.push_back({arr[j][i+1],j});
                    j--;
                }
            }
            temp=vec;
        }
        for(int i=0;i<a;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}