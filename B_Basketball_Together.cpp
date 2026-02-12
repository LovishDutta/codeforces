#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    int d;
    cin>>d;
    vector<int> arr(t);
    for(int i=0;i<t;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int total=t;
    int cnt=0;
    for(int i=t-1;i>=0;i--){
        int req=(d/arr[i]+1);
        if(req<=total){
            total-=req;
            cnt++;
        }
        else break;
    }
    cout<<cnt;
}