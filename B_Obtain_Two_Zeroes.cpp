#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int a,b;
        cin>>a>>b;
        if((2*b-a)%3==0&&(2*b-a)>=0){
            int x=(2*b-a)/3;
                if((a-x)%2==0&&a-x>=0){
                    cout<<"YES"<<endl;
                    continue;
                }
        }
        cout<<"NO"<<endl;
    }
}