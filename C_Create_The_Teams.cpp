#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,x;
        cin>>n>>x;
        vector<int> arr(n);
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mpp[ceil((double)x/arr[i])]++;
        }
        int ans=0,prev=0;
        for(auto &it:mpp){
            ans+=(it.second+prev)/it.first;
            prev=(it.second+prev)%it.first;
        }
        cout<<ans<<endl;
    }
}