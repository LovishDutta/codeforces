#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,s,x,sum=0;
        cin>>n>>s>>x;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
             cin>>arr[i];
             sum+=arr[i];
        }
        if(s-sum>=0&&(s-sum)%x==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}