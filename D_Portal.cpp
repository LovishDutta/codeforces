#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,x,y;
        cin>>n>>x>>y;
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++) cin>>arr[i];
        int mini=1e12,idx=-1;
        for(int i=x+1;i<=y;i++){
            if(arr[i]<mini){
                mini=arr[i];
                idx=i;
            }
        }
        vector<int> a;
        for(int i=x+1;i<=y;i++){
            a.push_back(arr[idx]);
            idx++;
            if(idx>y) idx=x+1;
        }
        vector<int> vec;
        for(int i=1;i<=x;i++) vec.push_back(arr[i]);
        for(int i=y+1;i<=n;i++) vec.push_back(arr[i]);
        bool flag=false;
        for(int i=0;i<vec.size();i++){
            if(!flag&&a[0]<vec[i]){
                flag=true;
                for(int j=0;j<a.size();j++) cout<<a[j]<<" ";
            }
            cout<<vec[i]<<" ";
        }
        if(!flag) for(int j=0;j<a.size();j++) cout<<a[j]<<" ";

        cout<<endl;
    }
}