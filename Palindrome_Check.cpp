#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k,f=1;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        int i=0,j=n-1;
        while(i<j){
            if(arr[i]==arr[j]){
                i++;
                j--;
            }
            else if(arr[i]==k){
                i++;
            }
            else if(arr[j]==k){
                j--;
            }
            else{
                f=0;
                break;
            }
        }
        if(f) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}