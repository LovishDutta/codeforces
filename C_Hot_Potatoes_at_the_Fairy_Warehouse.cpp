#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k,even=0,odd=0;
        cin>>n>>k;
        string s;
        cin>>s;
        for(int i=0;i<2*n;i++){
            if(s[i]=='1'){
                if(s[(i+1)%(2*n)]=='0'){
                    if(i%2==0) even++;
                    else odd++;
                }
                else{
                    if(i%2) even++;
                    else odd++;
                }
            }
        }
        cout<<even<<" "<<odd<<endl;
    }
}