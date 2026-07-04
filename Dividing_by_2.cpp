#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,cnt=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        while(true){
            int inc=0,mini=arr[0];
            for(int i=0;i<n;i++) mini=min(arr[i],mini);
            for(int i=0;i<n;i++){
                while(arr[i]>mini){
                    arr[i]/=2;
                    inc++;
                    cnt++;
                }
            }
            if(inc==0) break;
        }
        cout<<cnt<<endl;
    }
}