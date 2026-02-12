#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int ans=0;
        if(s[0]=='1') ans++;
        for(int i=1;i<s.size();i++){
            bool flag=false;
            if(s[i]=='1'){

                for(int j=i-1;j>=0&&j>=i-k+1;j--){
                    if(s[j]=='1'){
                        flag=true;
                        break;
                    }
                }
                if(!flag) ans++;
            }
        }
        cout<<ans<<endl;
    }
}