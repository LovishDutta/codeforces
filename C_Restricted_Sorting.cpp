#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,mini=INT_MAX,maxi=INT_MIN;
        cin>>n;
        vector<int> arr(n);
        vector<int> srt(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            srt[i]=arr[i];
            mini=min(mini,arr[i]);
            maxi=max(maxi,arr[i]);
        }
        sort(arr.begin(),arr.end());
        int k=1e12;
        for(int i=0;i<n;i++){
            if(arr[i]!=srt[i]){
                k=min(k,max(abs(arr[i]-maxi),abs(arr[i]-mini)));
            }
        }
        cout<<(k==1e12?-1:k)<<endl;
    }
}