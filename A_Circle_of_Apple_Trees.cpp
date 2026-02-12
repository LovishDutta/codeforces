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
        sort(arr.begin(),arr.end());
        int cnt=0,prev=-1;
        for(int i=0;i<n;i++){
            if(arr[i]>prev){ 
                cnt++;
                prev=arr[i];
            }
        }
        cout<<cnt<<endl;
    }
}