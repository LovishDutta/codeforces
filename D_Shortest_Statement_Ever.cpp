#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int x,y,fl=0;
        cin>>x>>y;
        if((x&y)==0){
            cout<<x<<" "<<y<<endl;
            continue;
        }
        if(y>x){
            swap(x,y);
            fl=true;
        }

        int p=0,q=0;
        int n = 64 - __builtin_clzll(x);
        int bits = 64 - __builtin_clzll(y);
        for(int i=n-1;i>=bits;i--) if(((x&(1LL<<i)))>0) p=(p|(1LL<<i));
        for(int i=0;i<bits;i++){
            // cout<<(1<<i)<<endl;
            int a=((x&(1LL<<i))>0),b=((y&(1LL<<i))>0);
            if(a==1&&b==1) p=(p|(1LL<<i));
            else if(a==0&&b==0) q=(q|(1LL<<i));
            else if(a==0&&b==1) q=(q|(1LL<<i));
            else p=(p|(1LL<<i));
            //cout<<a<<" "<<b<<endl;
        }
        if((x&(1LL<<bits))==0){
            if((1LL<<bits)-y<(y-q)) q=(1LL<<bits);
        }
        int ans=abs(x-p)+abs(y-q);
        if((x&(1LL<<bits))==0){
            int a=x;
            int b=(1LL<<bits);
            if(abs(x-a)+abs(y-b)<ans){
                p=a;
                q=b;
            }
        }
        if((y&(1LL<<n))==0){
            int a=(1LL<<bits);
            int b=y;
            if(abs(x-a)+abs(y-b)<ans){
                p=a;
                q=b;
            }
        }
        if(fl) cout<<q<<" "<<p<<endl;
        else cout<<p<<" "<<q<<endl;
    }
}