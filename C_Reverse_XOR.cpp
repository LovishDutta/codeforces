#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        int bits=log2(n);
        
        int a = 0, b = 0;
        int hold = n, pow = 1;
        bool check = true;

        while(hold>0){
            if(hold%2==1){
                break;
            }
            hold/=2;
        }

        n = hold;

        while(hold>0){
            b = b<<1;
            if(hold%2==1){
                if(check){
                    a += pow;
                    b = b|1;
                    check = false;
                }
                else check = true;
            }
            pow *= 2;
            hold/=2;
        }

        

        if((a^b)==n){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}