#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k,p,m,cnt=0;
        cin>>n>>k>>p>>m;
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i].first;
            if(i==p-1) arr[i].second=1;
            else arr[i].second=0;
        }
        while(m>0){
            int idx=0,mini=arr[0].first,a=arr[0].second;
            for(int i=0;i<k;i++){
                if(arr[i].second){
                    idx=i;
                    mini=arr[i].first;
                    a=arr[i].second;
                    break;
                }
                if(arr[i].first<mini){
                    idx=i;
                    mini=arr[i].first;
                    a=arr[i].second;
                }
            }
            if(m-mini>=0){
                m-=mini;
                if(arr[idx].second) cnt++;
            }
            else break;
            for(int i=idx;i<n-1;i++){
                arr[i].second=arr[i+1].second;
                arr[i].first=arr[i+1].first;
            }
            arr[n-1].first=mini;
            arr[n-1].second=a;
        }
        cout<<cnt<<endl;
    }
}