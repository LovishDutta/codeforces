#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,cnt1=0,cnt2=0;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        for(int i=0;i<n;i++) if(s1[i]==')') cnt1++;
        for(int i=0;i<n;i++) if(s2[i]==')') cnt2++;
        if(cnt1+cnt2!=n){
            cout<<"NO"<<endl;
            continue;
        }
        int ct1=0,ct2=0,s1cl=0,s2cl=0,flag=1;
        for(int i=0;i<n;i++){
            if(s1[i]==')') s1cl++;
            if(s2[i]==')') s2cl++;
            if(s2[i]==')'&&s1[i]=='(') ct1++;
            if(s2[i]=='('&&s1[i]==')') ct2++;
            if(s1cl>(i+1)/2){
                s1cl--;
                s2cl++;
                ct2--;
                if(ct2<0||s2cl>(i+1)/2){
                    flag=0;
                    break;
                }
            }
            if(s2cl>(i+1)/2){
                s2cl--;
                s1cl++;
                ct1--;
                if(ct1<0||s1cl>(i+1)/2){
                    flag=0;
                    break;
                }
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}