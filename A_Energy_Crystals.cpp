#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int x;
        cin>>x;
        vector<int> arr(3,0);
        int cnt=0;
        while(arr[0]<x||arr[1]<x||arr[2]<x){
            if(cnt%3==0){
                int a=min(arr[1],arr[2]);
                if(a==0||a%2!=0) arr[0]=2*a+1;
                else arr[0]=2*a;
            }
            else if(cnt%3==1){
                int a=min(arr[0],arr[2]);
                if(a==0||a%2!=0) arr[1]=2*a+1;
                else arr[1]=2*a;
            }
            else{
                int a=min(arr[0],arr[1]);
                if(a==0||a%2!=0) arr[2]=2*a+1;
                else arr[2]=2*a;
            }
            cnt++;
        }
        cout<<cnt<<endl;
    }
}