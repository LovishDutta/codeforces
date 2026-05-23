#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,a;
    cin>>n;
    vector<vector<int>> arr(3);
    for(int i=0;i<n;i++){
        cin>>a;
        arr[a%3].push_back(i);
    }
    string s(n,'1');
    if(arr[0].size()<=n/2){
        int cnt=0;
        for(int i=0;i<arr[0].size();i++){
            s[arr[0][i]]='0';
            cnt++;
        }
        for(int i=0;i<arr[1].size();i++){
            if(cnt==n/2) break;
            s[arr[1][i]]='0';
            cnt++;
        }
        for(int i=0;i<arr[2].size();i++){
            if(cnt==n/2) break;
            s[arr[2][i]]='0';
            cnt++;
        }
        cout<<0<<endl;
        cout<<s<<endl;
    }
    else{
        int cnt=0;
        for(int i=0;i<arr[1].size();i++){
            s[arr[1][i]]='0';
            cnt++;
        }
        for(int i=0;i<arr[2].size();i++){
            if(cnt==n/2) break;
            s[arr[2][i]]='0';
            cnt++;
        }
        for(int i=0;i<arr[0].size();i++){
            if(cnt==n/2) break;
            s[arr[0][i]]='0';
            cnt++;
        }
        cout<<2<<endl;
        cout<<s<<endl;
    }
}