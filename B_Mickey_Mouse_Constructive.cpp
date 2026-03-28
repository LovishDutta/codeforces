#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=676767677;
int div(int n) {
    int cnt = 0;  
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            if(i * i == n) 
                cnt += 1;    
            else 
                cnt += 2;
        }
    }
    return cnt;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int x,y;
        cin>>x>>y;
        if(x==y){
            cout<<1<<endl;
            for(int i=0;i<x;i++) cout<<1<<" ";
            for(int i=0;i<y;i++) cout<<-1<<" ";
            cout<<endl;
            continue;
        }
        else if(x==0){
            cout<<div(y)%mod<<endl;
            for(int i=0;i<y;i++) cout<<-1<<" ";
            cout<<endl;
            continue;
        }
        else if(y==0){
            cout<<div(x)%mod<<endl;
            for(int i=0;i<x;i++) cout<<1<<" ";
            cout<<endl;
            continue;
        }
        cout<<div(abs(x-y))%mod<<endl;
       
    if(x>y){
        for(int i=0;i<x-y;i++) cout<<1<<" ";
        for(int i=0;i<y;i++) cout<<1<<" "<<-1<<" ";
    }
    else{
        for(int i=0;i<y-x;i++) cout<<-1<<" ";
        for(int i=0;i<x;i++) cout<<-1<<" "<<1<<" ";
    }
        cout<<endl;
    }
}