#include<bits/stdc++.h>
using namespace std;
#define int long long
bool f(int& mid,vector<int>& arr,int& m,int& w,int& n){
    int ans=0,sum=0;
    vector<int> dif(n,0);
    for(int i=0;i<n;i++){
        sum=sum-dif[i];
        if(sum+arr[i]<mid){
            ans+=(mid-sum-arr[i]);
            if(i+w<n) dif[i+w]+=(mid-sum-arr[i]);
            sum+=(mid-sum-arr[i]);
        }
        if(ans>m) return false;
    }
    return true;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,w,maxi=0;
    cin>>n>>m>>w;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
    }
    int low=0,high=maxi+m;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(f(mid,arr,m,w,n)) low=mid+1;
        else high=mid-1;
    }
    cout<<high;
}