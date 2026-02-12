#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,m,h;
        cin>>n>>m>>h;
    vector<int> arr(n,0),b(m,0),c(m,0);
    for (int i = 0; i < n; i++) cin>>arr[i];
    for (int i = 0; i < m; i++){
        cin>>b[i]>>c[i];
        b[i]--;
    }
    int ind = -1;
    map<int,int> mpp;
    for (int i = 0; i < m; i++){
        if(arr[b[i]] + mpp[b[i]] + c[i]>h){
            ind = i;
            mpp.clear();
        }
        else{
            mpp[b[i]] += c[i];
        }
    }
    for (int i = ind+1; i < m; i++)
    {
        arr[b[i]] = arr[b[i]] + c[i];  
    }
    int k=0;
    for (k=0; k < n; k++)
    {
        cout<<arr[k]<<" ";
    }
    cout<<endl;
    }
}