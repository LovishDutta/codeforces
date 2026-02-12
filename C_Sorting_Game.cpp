#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,cnt=0;
        cin>>n;
        string s;
        cin>>s;
        string s2=s;
        sort(s2.begin(),s2.end());
        bool flag=false;
        if(s2==s) cout<<"Bob"<<endl;
        else{
            int i=0,j=n-1;
            vector<int> zero;
            vector<int> one;
            cout<<"Alice"<<endl;
            while(i<=j){
                if(one.size()==zero.size()){
                    if(s[i]=='1'){
                        one.push_back(i);
                    }
                    i++;
                }
                else{
                    if(s[j]=='0'){
                        zero.push_back(j);
                    }
                    j--;
                }
            }
            cout<<2*zero.size()<<endl;
            for(int k=0;k<zero.size();k++){
                cout<<one[k]+1<<" ";
            }
            for(int k=zero.size()-1;k>=0;k--){
                cout<<zero[k]+1<<" ";
            }
            cout<<endl;
        }
    }
}