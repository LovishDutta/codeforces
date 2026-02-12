#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int arr[n];
        string s;
        cin>>s;
        int mini=1,maxi=n;
        int k=n-1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='<'){
                arr[k]=mini++;
            }
            else arr[k]=maxi--;
            k--;
        }
        arr[0]=mini;
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}