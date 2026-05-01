#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,a;
        cin>>n;
        vector<int> arr;
        vector<int> two;
        vector<int> three;
        vector<int> six;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a%6==0) six.push_back(a);
            else if(a%3==0) three.push_back(a);
            else if(a%2==0) two.push_back(a);
            else arr.push_back(a);
        }
        for(int i=0;i<two.size();i++) cout<<two[i]<<" ";
        for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
        for(int i=0;i<three.size();i++) cout<<three[i]<<" ";
        for(int i=0;i<six.size();i++) cout<<six[i]<<" ";
        cout<<endl;
    }
}