#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,ans=0;
        cin>>n;
        string s;
        cin>>s;
        vector<int> arr;
        for(int i=0;i<n;i++){   
            char ch=s[i];
            int cnt=0,j=i;
            while(j<n&&s[j]==ch){
                j++;
                cnt++;
            }
            arr.push_back(cnt);
            i=j-1;
        }
        for(int i=0;i<arr.size();i++) ans+=arr[i]/3;
        cout<<ans<<endl;
    }
}