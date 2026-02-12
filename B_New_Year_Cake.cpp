#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int a,b,p=1,cnt1=0,cnt2=0;
        cin>>a>>b;
        int c=a,d=b;
        while(true){
            if(cnt1%2){
                if(p<=c){
                    c-=p;
                }
                else break;
            }
            else{
                if(p<=d){
                    d-=p;
                }
                else break;
            }
            p*=2;
            cnt1++;
        }
        p=1;
        while(true){
            if(cnt2%2){
                if(p<=b){
                    b-=p;
                }
                else break;
            }
            else{
                if(p<=a){
                    a-=p;
                }
                else break;
            }
            p*=2;
            cnt2++;
        }
        cout<<max(cnt1,cnt2)<<endl;
    }
}