#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k=-1,flag=1;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1]) continue;
            else{
                k=max(k,arr[i-1]-arr[i]);
            }
        }
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1]) continue;
            else{
                if(k==-1){
                    k=arr[i-1]-arr[i];
                }
                arr[i]+=k;
                if(arr[i]<arr[i-1]){
                    flag=0;
                    break;
                }
            }
        }
        // arr[n-1]+=1e15;
        // for(int i=n-1;i>=0;i--){
        //     if(arr[i]>arr[i+1])
        // }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}