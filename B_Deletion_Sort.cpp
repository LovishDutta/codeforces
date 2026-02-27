#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
    int n,flag=true;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
         cin>>arr[i];
         if(i>0&&arr[i]<arr[i-1]) flag=false;
    }
    if(flag) cout<<n<<endl;
    else cout<<1<<endl;
    }
}