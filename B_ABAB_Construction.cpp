#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,ans=1;
        cin>>n;
        string s;
        cin>>s;
        int rema=(n+1)/2,remb=n/2,a=0,b=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                 a++;
            }
            else if(s[i]=='b'){
                 b++;
            }

        }
        rema-=a;
        remb-=b;
        if(rema<0||remb<0) ans=0;
        if(n%2==1){
        if(s[0]=='b') ans=0;
        if(n>2){
            if(s[1]=='a'&&s[2]=='a') ans=0;
            if(s[1]=='b'&&s[2]=='b') ans=0;
        }
        for(int i=3;i<n-1;i+=2){
            if(s[i]=='a'){
                if(s[i+1]=='a'){
                    ans=0;
                    break;
                }
                else if(s[i+1]=='?'){
                    if(remb<=0){
                        ans=0;
                        break;
                    }
                    remb--;
                    s[i+1]='b';
                }
            }
            if(s[i]=='b'){
                if(s[i+1]=='b'){
                    ans=0;
                    break;
                }
                else if(s[i+1]=='?'){
                    if(rema<=0){
                        ans=0;
                        break;
                    }
                    rema--;
                    s[i+1]='a';
                }
            }
        }
    }
    else{
        for(int i=0;i<n-1;i+=2){
            if(s[i]=='a'){
                if(s[i+1]=='a'){
                    ans=0;
                    break;
                }
                else if(s[i+1]=='?'){
                    if(remb<=0){
                        ans=0;
                        break;
                    }
                    remb--;
                    s[i+1]='b';
                }
            }
            if(s[i]=='b'){
                if(s[i+1]=='b'){
                    ans=0;
                    break;
                }
                else if(s[i+1]=='?'){
                    if(rema<=0){
                        ans=0;
                        break;
                    }
                    rema--;
                    s[i+1]='a';
                }
            }
        }
    }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}