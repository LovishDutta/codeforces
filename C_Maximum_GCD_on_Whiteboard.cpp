#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        map<int,int> mpp;
        for(auto& it:arr) mpp[it]++;
        int ans=1;
        for(int i=n;i>=1;i--){
            int idx=lower_bound(arr.begin(),arr.end(),4*i)-arr.begin();
            if(idx-mpp[i]-mpp[2*i]-mpp[3*i]<=k){
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
}