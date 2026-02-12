#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            int c;
            cin>>c;
            arr[i]=c;
        }
        int arrcount=1;
        int prev=arr[0];
        for(int i=1;i<n;i++){
            if(prev+1<arr[i]){
                arrcount++;
                prev=arr[i];
            }
        }
        cout<<arrcount<<endl;
    }
}