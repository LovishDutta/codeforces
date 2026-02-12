#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
int n;
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++) cin>>arr[i];
map<int,int> col;
for(int i=0;i<n;i++){
    if(i%2) col[arr[i]]=1;
    else col[arr[i]]=2;
}
sort(arr.begin(),arr.end());
bool flag=true;
for(int i=0;i<n-1;i++){
    if(col[arr[i]]==col[arr[i+1]]){
        flag=false;
        break;
    }
}
if(flag) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
    }
}