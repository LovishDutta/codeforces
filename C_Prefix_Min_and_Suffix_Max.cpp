#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n),maxi(n,INT_MIN),mini(n,INT_MAX);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        mini[0]=arr[0];
        maxi[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            mini[i]=min(arr[i],mini[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            maxi[i]=max(arr[i],maxi[i+1]);
        }
        string ans="1";
        for(int i=1;i<n-1;i++){
            if(mini[i-1]<arr[i]&&maxi[i+1]>arr[i]) ans.push_back('0');
            else ans.push_back('1');
        }
        ans.push_back('1');
        cout<<ans<<endl;
    }
}