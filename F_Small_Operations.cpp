#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int> mpp;
int recur(int i,vector<vector<int>>& arr,vector<int>& start){
    if(i>=arr.size()) return 0;
    if(mpp.find(i)!=mpp.end()) return mpp[i];
    int notpick=recur(i+1,arr,start);
    int pick=arr[i][2]+recur(upper_bound(start.begin(),start.end(),arr[i][1])-start.begin(),arr,start);
    return mpp[i]=max(pick,notpick);
}
signed main(){
    int n;
    cin>>n;
    vector<vector<int>> arr;
    vector<int> temp(3);
    for(int i=0;i<n;i++){
        cin>>temp[0];
        cin>>temp[1];
        cin>>temp[2];
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    vector<int> start(n);
    for(int i=0;i<n;i++){
        start[i]=arr[i][0];
    }
    cout<<recur(0,arr,start);
}