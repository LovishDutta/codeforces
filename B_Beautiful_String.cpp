#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        string s(n,'0');
        cin>>s;
         vector<int> arr;
        for(int i=0;i<n;i++){
            if(s[i]=='0') arr.push_back(i+1);
        }
        if(arr.size()==n||arr.size()==0) cout<<0<<endl;
        else{
            cout<<arr.size()<<endl;
            for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        }

    }
}