#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> f(int n){
    int a=-1,b=-1;
    for(int i=1;i<=(1<<30);i*=2){
            if(((n+i)&(n+i-1))==0){
                a=i;
                b=n+i;
                break;
            }
    }
    return {a,b};
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,sm=0;
        cin>>n;
        vector<int> arr(n);
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sm+=arr[i];
        }
        if(sm%n!=0){
            cout<<"No"<<endl;
            continue;
        }
        int avg=sm/n,flag=1;
        for(int i=0;i<n;i++){
            if(arr[i]-avg>0){
                pair<int,int> p=f(arr[i]-avg);
                if(p.first==-1){
                    flag=0;
                    break;
                }
                mpp[p.first]++;
                mpp[p.second]--;
            }
            else if(arr[i]-avg<0){
                pair<int,int> p=f(avg-arr[i]);
                if(p.first==-1){
                    flag=0;
                    break;
                }
                mpp[p.second]++;
                mpp[p.first]--;
            }
        }
        for(auto &it:mpp){
             if(it.second!=0){
                 flag=0;
                 break;
             }
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        
    }
}