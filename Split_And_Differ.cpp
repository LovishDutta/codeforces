#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(vector<int>& arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        if(arr[i]==0||arr[i+1]==0) return false;
        if(arr[i]==arr[i+1]) return false;
    }
    return true;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<int> b;
        b.push_back(arr[0]);
        for(int i=1;i<n;i++){
            int prev=b[b.size()-1];
            if(arr[i]!=prev) b.push_back(arr[i]);
            else{
                if(i+1<n&&arr[i+1]==1){
                    b.push_back(1);
                    b.push_back(arr[i]-1);
                }
                else{
                    b.push_back(arr[i]-1);
                    b.push_back(1);
                }
            }
        }
        if(!check(b)) cout<<-1<<endl;
        else{
            cout<<b.size()<<endl;
            for(int i=0;i<b.size();i++) cout<<b[i]<<" ";
            cout<<endl;
        }
    }
}