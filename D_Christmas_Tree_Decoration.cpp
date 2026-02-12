#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
int factorial(int n){
    int ans=1;
    for(int i=1;i<=n;i++){
        ans=(ans*i)%mod;
    }
    return ans;
}
int mult(int b,int a){
    int ans=1;
    for(int i=a+1;i<=b;i++){
        ans=(ans*i)%mod;
    }
    return ans;
}
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,a;
        cin>>n;
        vector<int> arr(n);
        cin>>a;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int ans=0;
        if(arr[n-1]!=arr[0]){
            for(int i=0;i<n-1;i++){
                if(arr[i]==arr[n-1]) break;
                if((arr[n-1]-arr[i]-1)<=a){
                    a-=(arr[n-1]-arr[i]-1);
                    arr[i]=arr[n-1]-1;
                }
                else{
                    ans=-1;
                    break;
                }
            }
        }
        if(ans==-1){
            cout<<0<<endl;
            continue;
        }
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        if(mpp.size()==1){
            cout<<factorial(n)<<endl;
        }
        else if(mpp.size()==2){
            if(a>=mpp[arr[0]]){
                cout<<factorial(n)<<endl;
            }
            else{
                a=(a)%n;
                cout<<((factorial(a+mpp[arr[n-1]])*(mult(mpp[arr[0]],a)))%mod)<<endl;
            }
        }
        else{
            cout<<0<<endl;
        }
    }
}
