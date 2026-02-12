#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i>0&&arr[i]==arr[i-1]) ans=0;
        } 
        if(ans!=INT_MAX){
            cout<<ans<<endl;
        }
        else{

            for(int i=0;i<n;i++){
                int target=arr[i];
                int t2=arr[i]+1;
                int t3=arr[i]-1;
                int cnt=-1;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                bool found=false;
                for(int j=i-1;j>=0;j--){
                        maxi=max(maxi,arr[j]);
                        mini=min(mini,arr[j]);
                        cnt++;
                    if((target<=maxi&&target>=mini)||(t2<=maxi&&t2>=mini)||(t3<=maxi&&t3>=mini)){
                      //  cout<<cnt<<"hi"<<endl;
                        found=true;
                        break;
                    }
                }
                if(found) ans=min(cnt,ans);
                found=false;
                cnt=-1;
                maxi=INT_MIN;
                mini=INT_MAX;
                for(int j=i+1;j<n;j++){
                    maxi=max(maxi,arr[j]);
                    mini=min(mini,arr[j]);
                    cnt++;
                    if((target<=maxi&&target>=mini)||(t2<=maxi&&t2>=mini)||(t3<=maxi&&t3>=mini)){
                     //   cout<<cnt<<"hi2"<<endl;
                        found=true;
                        break;
                    }
                }
                if(found) ans=min(cnt,ans);
            }
            if(ans==INT_MAX) cout<<-1;
            else cout<<ans;
            cout<<endl;
        }
    }
}