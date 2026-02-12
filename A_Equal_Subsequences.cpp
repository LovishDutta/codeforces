#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,k;
        cin>>n;
        cin>>k;
        string s="";
        for(int i=0;i<n;i++){
            if(i<k) s.push_back('1');
            else s.push_back('0');
        }
        cout<<s<<endl;
    }
}