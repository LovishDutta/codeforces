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
        size_t pos = s.find("2026");
        size_t pos2 = s.find("2025");
    if (pos != string::npos){
             cout<<'0'<<endl;
        }
    else if((pos2 != string::npos)){
        cout<<'1'<<endl;
    }
    else cout<<'0'<<endl;
    }
}