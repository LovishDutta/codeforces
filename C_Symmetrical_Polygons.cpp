#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int pairsum=0;
    int pair=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            pairsum+=2*arr[i];
            pair++;
            vis[i]=true;
            vis[i+1]=true;
            i++;
        }
    }
    if(pairsum==0){
        cout<<0<<endl;
        continue;
    }
    vector<int> unvis;
    for(int i=n-1;i>=0;i--){
        if(!vis[i]){
            unvis.push_back(arr[i]);
        }
    }
    int unvissum=0;
    if(unvis.size()!=0){
        for(int i=0;i<unvis.size()-1;i++){
            if(unvis[i]-unvis[i+1]<pairsum){
               unvissum+=unvis[i]+unvis[i+1];
               break;
            }
        }
        if(unvissum==0){
            for(int i=0;i<unvis.size();i++){
            if(unvis[i]<pairsum){
               unvissum+=unvis[i];
               break;
            }
        }
        }
    }
    if(pair==1&&!unvissum){
        cout<<0<<endl;
        continue;
    }
    cout<<pairsum+unvissum<<endl;
}
}