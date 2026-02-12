#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        string s;
        cin>>s;
        vector<int> arr(10,0);
        for(int i=0;i<10;i++){
            arr[s[i]-'0']++;
        }
       
        string ans="";
        for(int i=0;i<10;i++){
            for(int j=10-i-1;j<10;j++){
                if(arr[j]!=0){ 
                    ans.push_back(j+'0');
                    arr[j]--;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
}