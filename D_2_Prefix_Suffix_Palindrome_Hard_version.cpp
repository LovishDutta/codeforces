#include<bits/stdc++.h>
using namespace std;
#define int long long
int base1=31;
int mod1=1e9+7;
int base2=57;
int mod2=1e9+9;
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        string s,ans="";
        cin>>s;
        int m=s.size(),a=-1,b=-1,p=0,q=m-1;
        while(p<q&&s[p]==s[q]){
            ans.push_back(s[p]);
            p++;
            q--;
        }   
        string s2="",s3="",s4="";
        if(q-p+1>0) s2=s.substr(p,q-p+1); 
        else{
            cout<<ans;
            reverse(ans.begin(),ans.end());
            cout<<ans<<endl;
            continue;
        }
        int n=s2.size();
        vector<int> suff(n),pref(n);
        vector<int> suff1(n),pref1(n);
        vector<int> power(n+1),power1(n+1);
        power[0]=1;
        power1[0]=1;
        for(int i=1;i<=n;i++){
            power[i]=(power[i-1]*base1)%mod1;
            power1[i]=(power1[i-1]*base2)%mod2;
        }
        pref[0]=s2[0]-'a'+1;
        suff[n-1]=s2[n-1]-'a'+1;
        pref1[0]=s2[0]-'a'+1;
        suff1[n-1]=s2[n-1]-'a'+1;
        for(int i=1;i<n;i++){
            pref[i]=(pref[i-1]*base1+(s2[i]-'a'+1))%mod1;
            pref1[i]=(pref1[i-1]*base2+(s2[i]-'a'+1))%mod2;
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=(suff[i+1]*base1+(s2[i]-'a'+1))%mod1;
            suff1[i]=(suff1[i+1]*base2+(s2[i]-'a'+1))%mod2;
        }
        for(int i=0;i<n;i++){
            int h1=pref[i];
            int h2=(suff[0]-(i+1<n?(suff[i+1]*power[i+1])%mod1:0)+mod1)%mod1;
            int h3=pref1[i];
            int h4=(suff1[0]-(i+1<n?(suff1[i+1]*power1[i+1])%mod2:0)+mod2)%mod2;
            if(h1==h2&&h3==h4){
                if(i+1>b){
                    b=i+1;
                }
            }
        }
        if(b!=-1) s3=s2.substr(0,b);
        reverse(s2.begin(),s2.end());
        reverse(suff.begin(),suff.end());
        reverse(suff1.begin(),suff1.end());
        reverse(pref.begin(),pref.end());
        reverse(pref1.begin(),pref1.end());
        for(int i=0;i<n;i++){
            int h1=suff[i];
            int h2=(pref[0]-(i+1<n?(pref[i+1]*power[i+1])%mod1:0)+mod1)%mod1;
            int h3=suff1[i];
            int h4=(pref1[0]-(i+1<n?(pref1[i+1]*power1[i+1])%mod2:0)+mod2)%mod2;
            if(h1==h2&&h3==h4){
                if(i+1>a){
                    a=i+1;
                }
            }
        }
        if(a>b) s3=s2.substr(0,a);
        cout<<ans;
        cout<<s3;
        reverse(ans.begin(),ans.end());
        cout<<ans;
        cout<<endl;
    }
}