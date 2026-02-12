#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;   
    int n;
    int min=INT_MAX; 
    for(int i=0;i<t;i++){
        cin>>n;
        if(min>abs(n)) min=abs(n);
    }
    cout<<min;
}