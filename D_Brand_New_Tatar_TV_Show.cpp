#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k,ans=0;
        cin>>n>>k;
        vector<int> arr(n);
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mpp[arr[i]]++;
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            int end=i;
            //cout<<(arr[end+1]-arr[end]<=k)<<endl;
            while(end+1<n&&arr[end+1]-arr[end]<=k){
                end++;
                //cout<<"hi"<<endl;
            }
            if(arr[i]==arr[end]){
                if((end-i)%2==1) ans=1;
            }
            else{
                ans=1;
            }
            i=end;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}