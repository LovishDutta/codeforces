#include<bits/stdc++.h>
using namespace std;
signed main(){
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,cnt1=0,cnt2=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==0) cnt1++;
            if(arr[i]==-1) cnt2++;
        }
        cout<<cnt1+(cnt2%2)*2<<endl;
    }
}