#include<bits/stdc++.h>
using namespace std;
vector<int> f(int n) {
    vector<int> fib(n);
    fib[0]=1;
    fib[1]=2;
    for (int i = 2; i < n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib;
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,m;
        cin>>n;
        cin>>m;
        vector<int> temp(3);
        vector<vector<int>> arr;
        for(int i=0;i<m;i++){
            cin>>temp[0];
            cin>>temp[1];
            cin>>temp[2];
            arr.push_back(temp);
        }
        vector<int> fib;
        string s="";
        fib=f(n);
        for(int i=0;i<m;i++){
            bool ans=true;
            long vol=0;    
            for(int j=fib.size()-1;j>=0;j--){
                long a=fib[j];
                if(a<=arr[i][2]&&a<=arr[i][1]&&a<=arr[i][0]){
                if(arr[i][1]>=arr[i][0]&&arr[i][1]>=arr[i][2]) arr[i][1]-=a;
                else if(arr[i][2]>=arr[i][0]&&arr[i][2]>=arr[i][1]) arr[i][2]-=a;
                else arr[i][0]-=a;
            }
            else ans=false;
        }
        if(ans==true) s+='1';
        else s+='0';
    }
    cout<<s<<endl; 
}
}