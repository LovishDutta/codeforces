#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,x;
        cin>>n;
        cin>>x;
        long long ans=0;
        if(n%2){
            ans+=x;
            ans+=n-1;
            cout<<ans<<endl;
        }
        else{
            for(int a=1;a<=x;a++){
                if(a^x!=0){
                    ans+=a^x;
                    ans+=a;
                    break;
                }
            }
            cout<<ans<<endl;
        }
    }
}