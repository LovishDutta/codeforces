#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,c,k;
        cin>>n>>c>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(arr[i]<=c){
                if(c-arr[i]<=k){
                    int ele=(c-arr[i]);
                    arr[i]+=ele;
                    k-=ele;
                }
                else{
                    arr[i]+=min((c-arr[i]),k);
                    k=0;

                }
                c+=arr[i];
            }
            else break;
        }
        cout<<c<<endl;
    }
}