#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        string s;
        cin>>s;
        int n=s.size(),f=0,st=-1,ed=-1;
        for(int i=0;i<s.size();i++){
            if(i%2){
                if(s[i]!='b'){
                    st=i;
                    break;
                }
            }
            else{
                if(s[i]!='a'){
                    st=i;
                    break;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i%2){
                if(s[i]!='b'){
                    ed=i;
                    break;
                }
            }
            else{
                if(s[i]!='a'){
                    ed=i;
                    break;
                }
            }
        }
        if(st==-1){
            cout<<"YES"<<endl;
            continue;
        }
        string tar(ed-st+1,'1');
        string given2(ed-st+1,'1');
        for(int i=st;i<=ed;i++){
            if(i%2) tar[i-st]='b';
            else tar[i-st]='a';
        }
        string given=s.substr(st,(ed-st+1));
        reverse(given.begin(),given.end());
        for(int i=0;i<given.size();i++){
            if(given[i]=='a') given2[i]='b';
            else given2[i]='a';
        }
        if(tar==given||tar==given2){
            cout<<"YES"<<endl;
            continue;
        }
        st=-1,ed=-1;
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                if(s[i]!='b'){
                    st=i;
                    break;
                }
            }
            else{
                if(s[i]!='a'){
                    st=i;
                    break;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i%2==0){
                if(s[i]!='b'){
                    ed=i;
                    break;
                }
            }
            else{
                if(s[i]!='a'){
                    ed=i;
                    break;
                }
            }
        }
        if(st==-1){
            cout<<"YES"<<endl;
            continue;
        }
        string target(ed-st+1,'1');
        string giv2(ed-st+1,'1');
        for(int i=st;i<=ed;i++){
            if(i%2) target[i-st]='a';
            else target[i-st]='b';
        }
        string giv=s.substr(st,(ed-st+1));
        reverse(giv.begin(),giv.end());
        for(int i=0;i<giv.size();i++){
            if(giv[i]=='a') giv2[i]='b';
            else giv2[i]='a';
        }
        if(target==giv||target==giv2){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
}