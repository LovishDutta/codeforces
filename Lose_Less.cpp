#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int m,n,w=0;
        cin>>m>>n;
        while(true){
            if(2*w+m-n>=0){
                cout<<2*w+m-n<<endl;
                break;
            }
            w++;
        }
    }
}