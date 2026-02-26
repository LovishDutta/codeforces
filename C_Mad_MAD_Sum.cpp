#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,sum=0,mad=0,cnt=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
             cin>>arr[i];
             sum+=arr[i];
        }
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
            if(mpp[arr[i]]>1&&arr[i]>mad){
               if(i!=n-1) sum+=mad*(n-i)*(cnt-1);
                mad=arr[i];
                cnt=1;
            }
            sum+=cnt*mad;
            cnt++;
        }
        cout<<sum<<endl;
    }
}