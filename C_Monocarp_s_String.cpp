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
        int cnta=0,cntb=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a') cnta++;
            else cntb++;
        }
        if(cnta==cntb){
            cout<<0<<endl;
            continue;
        }
        int ans=-1;
        char ch=cnta>cntb?'a':'b';
        int diff=abs(cnta-cntb);
        for(int i=0;i<n;i++){
            int j=i;
            int consecutive=0;
            while(j<n&&s[j]==ch){
                j++;
                consecutive++;
            if(consecutive==diff&&diff!=n){
                ans=diff;
                break;
            }
            }
            if(ans!=-1) break;
            if(consecutive) i=j-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}