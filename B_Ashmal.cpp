#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<string> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        string s=a[0];
        for(int i=1;i<n;i++){
            string s1=s+a[i];
            string s2=a[i]+s;
            bool flag=false;
            int j=0;
            while(j<s1.size()){
                if(s1[j]<s2[j]) break;
                else if(s1[j]>s2[j]){
                    flag=true;
                    break;
                }
                j++;
            }
            if(flag) s=s2;
            else s=s1;
        }
        cout<<s<<endl;
    }
}