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
        string a,b;
        cin>>a>>b;
        vector<int> arr1,arr2;
        for(int i=0;i<n;i++){
            if(a[i]=='1') arr1.push_back(i);
            if(b[i]=='1') arr2.push_back(i);          
        }
        if(arr1.size()!=arr2.size()){
            cout<<-1<<endl;
            continue;
        }
        for(int i=0;i<arr1.size();i++) if(arr1[i]!=arr2[i]) cnt++;
        cout<<cnt<<endl;
    }
}