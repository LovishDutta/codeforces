#include<bits/stdc++.h>
using namespace std;
int main(){
        int m,s;
        cin>>m>>s;
        if(m==1&&s==0){
            cout<<"0 0";
            return 0;
        }
        string s1(m,'0');
        string s2(m,'9');
        s1[0]='1';
        int sum1=1;
        int sum2=9*m;
        bool ans=true;
        for(int i=m-1;i>=0;i--){
                if(s-sum1>9){
                     s1[i]='9';
                     sum1+=9;
                }
                else if(s-sum1>=0){
                    s1[i]=s1[i]+s-sum1;
                    sum1+=s-sum1;
                    break;
                }
                else{
                    ans=false;
                    break;
                }
        }
        for(int i=m-1;i>=0;i--){
                if(sum2-s>9){
                     s2[i]='0';
                     sum2-=9;
                }
                else if(sum2-s>=0){
                    s2[i]='9'-(sum2-s);
                     sum2-=(sum2-s);
                    break;
                }
                else{
                    ans=false;
                    break;
                }
        }
        if(ans) cout<<s1<<" "<<s2;
        else cout<<"-1 -1";

}