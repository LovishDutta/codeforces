#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<int> pref(n,-1);
        pref[0]=arr[0];
        for(int i=1;i<n;i++){
            pref[i]=max(pref[i-1],arr[i]);
        }
        int cnt=0;
        for(int i=n-1;i>=1;i--){
            if(pref[i-1]>arr[i]) cnt++;
        }
        cout<<cnt<<endl;
    }
}