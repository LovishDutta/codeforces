#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,a,b;
        cin>>n;
        int val=n%12;
        if(val<10){
            a=val;
            b=n-a;
        }
        else if(val==10){
            a=22;
            b=(n-a);
        }
        else if(val==11){
            a=11;
            b=n-a;
        }
        if(a+b==n&&a>=0&&b>=0) cout<<a<<" "<<b<<endl;
        else cout<<-1<<endl;
    }
}