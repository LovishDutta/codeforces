#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(int mid,int m,vector<int>& arr){
    int ans=0,n=arr.size(),cnt=0,p=0;
    for(int i=n-1;i>=0;i--){
        if(cnt!=0&&cnt%mid==0) p++;
        ans+=max(arr[i]-p,0LL);
        if(ans>=m) return true;
        cnt++;
    }
    return false;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,low=1,high=2e5+4,sum=0;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr.begin(),arr.end());
    if(sum<m){
        cout<<-1<<endl;
        return 0;
    }
    while(low<=high){
        int mid=(low+high)/2;
        if(check(mid,m,arr)) high=mid-1;
        else low=mid+1;
    }
    cout<<low<<endl;
}