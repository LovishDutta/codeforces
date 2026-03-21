#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        string s;
        cin>>s;
        n = s.size();
        if(n==1){
            cout<<s<<endl;
            continue;
        }
        vector<int> freq(10,0);
        int z = 0;
        for(int i=0;i<n;i++){
            freq[s[i]-'0']++;
            z+= s[i]-'0';
        } 
        for(int i=1;i<=z;i++){
            vector<int> req(10,0);
            int ele=i,sm=0,fl=true;
            while(i>=10&&ele>0){
                int r=ele%10;
                sm+=r;
                if(freq[r]-req[r]>0) req[r]++;
                else{
                    fl=false;
                    break;
                }
                ele=ele/10;
            }
            if(i<10) sm=ele;
            if(!fl) continue;
            vector<int> s2;
            while(sm>=10){
                int newsm=0;
                s2.push_back(sm);
                while(sm>0){
                int r=sm%10;
                newsm+=r;
                if(freq[r]-req[r]>0) req[r]++;
                else{
                    fl=false;
                    break;
                }
                sm=sm/10;
            }
            sm=newsm;
            if(!fl) break;
        }
        if(!fl) continue;
        s2.push_back(sm);
        if((freq[sm]-req[sm])>0) req[sm]++;
        else continue;
            int finalsum=0;
            for(int k=0;k<10;k++){
                finalsum+=(freq[k]-req[k])*k;
            }
            if(finalsum==i){
                for(int k=9;k>=0;k--){
                for(int j=0;j<(freq[k]-req[k]);j++) cout<<k;
                }
                if(i>=10) cout<<i;
                for(int k=0;k<s2.size();k++) cout<<s2[k];
                cout<<endl;
                break;
            }
        }
    }
}