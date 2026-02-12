#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    if(s=="first"){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        string s1;
        for(int i=0;i<n;i++){
            if(arr[i].size()==10) s1.push_back('l');
            else{
                for(int j=0;j<arr[i].size();j++){
                    s1.push_back('a'+arr[i][j]-'0');
                }
            }
            s1.push_back('k');
        }
        cout<<s1<<endl;
    }
    else{
        string s2;
        cin>>s2;
        vector<int> ans;
        int a=0;
        for(int i=0;i<s2.size();i++){
            if(s2[i]=='k'){
                ans.push_back(a);
                a=0;
            }
            else if(s2[i]=='l') a=1e9;
            else a=a*10+(s2[i]-'a');
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
}