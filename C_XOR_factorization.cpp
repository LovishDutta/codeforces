#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,k;
        cin>>n>>k;
        if(k%2==1){
            for(int i=0;i<k;i++) cout<<n<<" ";
        }
        else{
            int highest =31- __builtin_clz(n);
            vector<int> invalid(k,(1 << (highest+1)) - 1);
            vector<int> valid;
            int start=0;
           for(int i=highest;i>=0;i--){
            if(n&(1<<i)){
                if(start<k){
                    valid.push_back(invalid[start] & ~(1 << i));                  
                    start++;
                }
                else{
                    valid[0]=valid[0] & ~(1 << i);
                }
            }
            else{
                for(int j=start;j<k;j++){
                    invalid[j]=invalid[j] & ~(1 << i);
                }
                if((k-start)%2==1) valid[0]=valid[0] & ~(1 << i);
            }
           }
           for(int j=0;j<valid.size();j++) cout<<valid[j]<<" ";
           for(int j=start;j<invalid.size();j++) cout<<invalid[j]<<" ";
        }     
        cout<<endl;
        }
    }
