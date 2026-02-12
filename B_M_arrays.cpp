#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,m;
        cin>>n>>m;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<int> vec(m,0);
        for(int i=0;i<n;i++) vec[arr[i]%m]++;
        int ans=(vec[0]>0);
        for(int i=1;i<=m/2;i++){
            if(vec[i]>0&&vec[m-i]>0){
                if(vec[i]>vec[m-i]){
                    vec[i]-=vec[m-i];
                    vec[i]--;
                    ans+=vec[i];
                } 
                else if(vec[i]<vec[m-i]){
                    vec[m-i]-=vec[i];
                    vec[m-i]--;
                    ans+=vec[m-i];
                }
                ans++;
            }
            else if(vec[i]>0||vec[m-i]>0){
                ans+=vec[i];
                ans+=vec[m-i];
            }
        }
        cout<<ans<<endl;
    }
}