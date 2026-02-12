#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int k=0;k<t;k++){
        int n,x;
        cin>>n;
        cin>>x;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int teamsize=0;
        int cnt=0;
        int mini=arr[0];
        for(int i=n-1;i>=0;i--){
            if(arr[i]>=x) cnt++;
            else{
                mini=arr[i];
                teamsize++;
                if(mini*teamsize>=x){
                    cnt++;
                    teamsize=0;
                }
            }
        }

        cout<<cnt<<endl;
    }
}