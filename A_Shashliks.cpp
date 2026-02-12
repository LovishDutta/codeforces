#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        long long a,b,k1,x,y;
        cin>>k1;
        cin>>a;
        cin>>b;
        cin>>x;
        cin>>y;
        long long ans1=0,ans2=0;
        if(x<y){
        if(k1>=a){
            ans1+=(k1-a)/x+1;
            k1-=ans1*x;
        }
        if(k1>=b){
            ans1+=(k1-b)/y+1;
            k1-=ans1*y;
        }
        }
        else if(x>y){
        if(k1>=b){
            ans1+=(k1-b)/y+1;
            k1-=ans1*y;
        }
        if(k1>=a){
            ans1+=(k1-a)/x+1;
            k1-=ans1*x;
        }
        }
        else if(k1>=min(a,b)){
            if(a<b){
            ans1+=(k1-a)/x+1;
            k1-=ans1*x;
            }
            else{
             ans1+=(k1-b)/x+1;
            k1-=ans1*x;   
            }
        }
        cout<<ans1<<endl;
        }

    }