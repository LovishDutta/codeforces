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
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int maxi=-1;
        int mini=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(i%2){
                if(maxi==-1||arr[maxi]<arr[i]){
                    maxi=i;
                }
            }
            else{
                if(mini==-1||arr[mini]>arr[i]){
                    mini=i;
                }
            }
        }
        //cout<<maxi<<" "<<mini<<endl;
        if(arr[maxi]>arr[mini]){
            int check;
            if(n%2) check=n-1;
            else check=n-2;
            int inddiff=abs(maxi-mini);
            int diff=arr[maxi]-arr[mini];
            if(diff+inddiff>check){
                swap(arr[maxi],arr[mini]);
                ans+=inddiff;
            }

        }
        else{
            int check;
            if(n%2) check=n-1;
            else check=n-2;
            ans+=check;
        }
        for(int i=0;i<n;i++){
            if(i%2){
                ans-=arr[i];
            }
            else ans+=arr[i];
        }
        
        cout<<ans<<endl;
    }
}