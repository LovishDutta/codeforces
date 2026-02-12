#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(2*n+1,0);
        for(int i=1;i<2*n+1;i++) cin>>arr[i];
        vector<int> ans(n+1,0);
        vector<int> subarr(2*n+1,0);
        vector<int> posarr(2*n+1,0);
        vector<int> alt1(2*n+1,0);
        vector<int> alt2(2*n+1,0);
        for(int i=1;i<2*n+1;i++){
            subarr[i]=subarr[i-1]-arr[i];
            posarr[i]=posarr[i-1]+arr[i];
           if(i%2==0){
             alt1[i]=alt1[i-1]+arr[i];
             alt2[i]=alt2[i-1]-arr[i];
           }
            else{
                alt1[i]=alt1[i-1]-arr[i];
                alt2[i]=alt2[i-1]+arr[i];
            }
        }
        int cnt=0;
        int k=n;
        while(cnt<n){
            ans[k]=posarr[2*n]+subarr[k]-posarr[k+2*cnt];
            if(k%2) ans[k]+=(alt1[k+2*cnt]-alt1[k]);
            else ans[k]+=(alt2[k+2*cnt]-alt2[k]);
            cnt++;
            k--;
        }
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}