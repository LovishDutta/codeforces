#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isinc(vector<int>& nums){
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
int funct(vector<int>& nums,int& mini){
    int idx=0,n=nums.size(),ans=1e12,idx2=n;
    vector<int> temp,temp2;
    for(int i=n-1;i>=0;i--){
        if(nums[i]==mini){
            idx=i;
            while(idx>=1&&nums[idx-1]==mini) idx--;
            break;
        }
    }
    for(int i=idx;i<n;i++) temp.push_back(nums[i]);
    for(int i=0;i<idx;i++) temp.push_back(nums[i]);
    if(isinc(temp)) ans=min(idx==0?0:(n-idx),ans);
    for(int i=n-1;i>=0;i--){
        if(nums[i]==mini) break;
        else idx2=i;
    }
    for(int i=idx2-1;i>=0;i--) temp2.push_back(nums[i]);
    for(int i=n-1;i>=idx2;i--) temp2.push_back(nums[i]);
    if(isinc(temp2)) ans=min((n-idx2)+1,ans);
    return ans;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,mini=1e12,ans=1e12;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mini=min(mini,arr[i]);
        }
        ans=min(ans,funct(arr,mini));
        reverse(arr.begin(),arr.end());
        ans=min(ans,funct(arr,mini)+1);
        if(ans>=1e12) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}