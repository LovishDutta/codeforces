#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        string s;
        int cnt=0;
        for(int i=0;i<n;i++){
            char c;
            cin>>c;
            s.push_back(c);
            if(s[i]=='1') cnt++;
        }
        int j=n-1;
        int ans=0;
        while(cnt){
            if(s[j]=='0') ans++;
            cnt--;
            j--;
        }
        cout<<ans<<endl;
    }
}