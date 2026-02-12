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
        vector<int> arr1(26,0);
        vector<int> arr2(26,0);
        bool ans=false;
        for(int i=0;i<n-1;i++){
            arr1[s[i]-'a']++;
            if(arr1[s[i]-'a']>1){
                ans=true;
                break;
            }
        }
        if(ans==false){
            for(int i=n-1;i>0;i--){
                arr2[s[i]-'a']++;
                if(arr2[s[i]-'a']>1){
                    ans=true;
                    break;
                }
            }
        }
        if(ans) cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    }
}