#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int c;
            cin>>c;
            arr.push_back(c);
        }
        sort(arr.begin(),arr.end());
        int ans=INT_MAX;
        if(arr[0]%2==0){
            int cnt=0;
            for(int i=n-1;i>=0;i--){
                if(arr[i]%2==0){
                    ans=min(ans,cnt);
                    break;
                }
                else cnt++;
            }
        }
        else{
            int cnt=0;
            for(int i=n-1;i>=0;i--){
                if(arr[i]%2!=0){
                    ans=min(ans,cnt);
                    break;
                }
                else cnt++;
            }
        }
        if(arr[n-1]%2==0){
             int cnt=0;
            for(int i=0;i<n;i++){
                if(arr[i]%2==0){
                    ans=min(ans,cnt);
                    break;
                }
                else cnt++;
            }
        }
        else{
            int cnt=0;
            for(int i=0;i<n;i++){
                if(arr[i]%2!=0){
                    ans=min(ans,cnt);
                    break;
                }
                else cnt++;
            }
        }
        cout<<ans<<endl;
    }
}