#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int a,b;
        cin>>a>>b;
        int k=a^b;
        bool flag=true;
        vector<int> arr;
    int bits = floor(log2(k)) + 1;
    for (int n = 0; n < bits; n++) {
        if (k & (1 << n)) {
            int f = (1 << n);
            if(f<=a){
                arr.push_back(f);
            }
            else{
                flag=false;
                break;
            }
        }
    }
    if(flag&&arr.size()<=100){
        cout<<arr.size()<<endl;
        if(arr.size()==0) continue;
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    else cout<<-1<<endl;
    }
}