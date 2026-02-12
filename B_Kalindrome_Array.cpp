#include<bits/stdc++.h>
using namespace std;
bool func(vector<int>& arr,int i,int j,int removed){
     while(i<j){
        while(i<=j&&arr[i]==removed) i++;
        while(i<=j&&arr[j]==removed) j--;
        if(i>=j) break;
        if(arr[i]==arr[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
       }
       return true; 
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
       int n;
       cin>>n;
       vector<int> arr(n);
       for(int i=0;i<n;i++) cin>>arr[i];
       int i=0,j=n-1;
       bool ans=true;
       while(i<j){
        if(arr[i]==arr[j]){
            i++;
            j--;
        }
        else{
            ans=func(arr,i,j,arr[i])||func(arr,i,j,arr[j]);
            break;
        }
       } 
       if(ans) cout<<"YES";
       else cout<<"NO";
       cout<<endl;
    }
}