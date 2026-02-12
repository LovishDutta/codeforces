#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        long long n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
    long long a1=arr[0];
    long long a2=arr[1];
    bool ans=true;
    long long y=(2*a1-a2)/(n+1);
    long long x=a1-n*y;
    if((2*a1-a2)%(n+1)!=0||x<0||y<0) ans=false;
    else{

        for(long long i=0;i<n;i++){
            if((i+1)*x+(n-i)*y!=arr[i]){
                ans=false;
                break;
            }
        }
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
}