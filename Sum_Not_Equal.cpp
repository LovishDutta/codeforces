#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        cin>>n;
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i].first;
            arr[i].second=i+1;
        }
        sort(arr.begin(),arr.end());
        int a=arr[n-1].first;
        int c=arr[0].first;
        int b=arr[1].first;
        if(a+b==c){
            cout<<-1<<endl;
            continue;
        }
        cout<<arr[n-1].second<<" "<<arr[1].second<<" "<<arr[0].second<<endl;
    }
}