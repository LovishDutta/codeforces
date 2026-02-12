#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int k=0;k<t;k++){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int cnt0=0,cnt1=0,cnt2=0,cnt5=0,cnt3=0;
        int i=0;
        for(i=0;i<n;i++){
            if(arr[i]==0) cnt0++;
            else if(arr[i]==1) cnt1++;
            else if(arr[i]==3) cnt3++;
            else if(arr[i]==2) cnt2++;
            else if(arr[i]==5) cnt5++;
            if(cnt0>=3&&cnt2>=2&&cnt3>=1&&cnt5>=1&&cnt1>=1){ 
                cout<<i+1<<endl;
                break;
            }
        }
        if(i==n&&!(cnt0>=3&&cnt2>=2&&cnt3>=1&&cnt5>=1&&cnt1>=1)) cout<<0<<endl;
    }
}