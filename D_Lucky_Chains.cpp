#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int x,y,cnt=0;
        cin>>x>>y;
        if(y-x==1){
            cout<<-1<<endl;
            continue;
        }
        while(__gcd(x,y)==1){
            x++;
            y++;
            cnt++;
        }
        cout<<cnt<<endl;
    }
}