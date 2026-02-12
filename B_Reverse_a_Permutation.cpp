#include<bits/stdc++.h>
using namespace std;
int f(vector<int>& arr,int maxi){
    int i=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==maxi) return i;
    }
    return i;
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int maxi=n;
        for(int i=0;i<n;i++){
            if(arr[i]!=maxi){
                reverse(arr.begin()+i,arr.begin()+f(arr,maxi)+1);
                break;
            }
            maxi--;
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}