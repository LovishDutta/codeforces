#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,l,r;
        cin>>n>>l>>r;
        vector<int> arr(n+2);
        for(int i=1;i<=n;i++) arr[i]=(i^(i-1));
        arr[r]=((r-1)^(l-1));
        arr[r+1]=(r+1)^(l-1);
        for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
} 