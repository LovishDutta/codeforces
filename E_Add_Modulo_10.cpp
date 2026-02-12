#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        int equal=-1;
        bool ans=true;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%2) arr[i]+=arr[i]%10;
            if(!(arr[i]%10)&&equal==-1) equal=arr[i];
        }
        if(equal!=-1){
            for(int i=0;i<n;i++){
            if(arr[i]!=equal){
                ans=false;
                cout<<"No"<<endl;
                break;
            }
        }
        if(ans) cout<<"Yes"<<endl;
        continue;
        }
        equal=arr[0]%20;
        for(int i=1;i<n;i++){
            int num=arr[i]%20;
            if(equal<num) swap(equal,num);
            while(num<equal){
                num+=num%10;
            }
            if(num!=equal){
                ans=false;
                break;
            }

        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}