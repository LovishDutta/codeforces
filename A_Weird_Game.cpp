#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    n*=2;
    string s1(n,'0');
    string s2(n,'0');
    for(int i=0;i<n;i++){
        cin>>s1[i];
    }
    for(int i=0;i<n;i++){
        cin>>s2[i];
    }
    int first=0,second=0;
    int a=0;
    for(int i=0;i<n;i++){
        if(s1[i]=='1'&&s2[i]=='1') a++;
        else{
            if(s1[i]=='1') first++;
            if(s2[i]=='1') second++;
        }
    }
    bool turn=true;
    if(a%2!=0){
        turn=false;
    }
    if(turn){
        if(first>second){
            cout<<"First";
        }
        else if(first==second){
            cout<<"Draw";
        }
        else{
            if(first+1==second) cout<<"Draw";
            else cout<<"Second";
        }
    }
    else{
        if(second>first){
            if(second<=first+2){
                cout<<"Draw";
            }
            else cout<<"Second";
        }
        else if(first==second){
            cout<<"First";           
        }
        else{
            cout<<"First";
        }
    }
    return 0;
}