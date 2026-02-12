#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int idx=0,cnt=0,open=0,ans=0,flag=false;
        while(idx<n&&s[idx]!=')') idx++;
        open=idx+1;
        while(idx<n&&s[idx]!='('){
             idx++;
            if(open>0){
             open--;
             ans+=2;
            }
        }
        open++;
        ans-=2;
        for(int i=idx;i<n;i++){
            if(s[i]==')') cnt++;
            if(cnt>=open){
                ans+=2*open;
                while(i<n&&s[i]!='(') i++;
                ans+=n-i;
                open=0;
                break;
            }
        }
        if(!open) cout<<n-2<<endl;
        else cout<<-1<<endl;
    }
}