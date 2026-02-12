#include<bits/stdc++.h>
using namespace std;
string func(int n){
    string s1(n/2,'4');
    string s2(n/2,'7');
    return s1+s2;
}
int main(){
        string s;
        cin>>s;
        int n=s.size();
        if(n%2){
            cout<<func(n+1);
        }
        else{
            string s1=func(n);
            reverse(s1.begin(),s1.end());
            if(s>s1){
                cout<<func(n+2);
            }
            else{
                reverse(s1.begin(),s1.end());
                    while (s1<s){
                        next_permutation(s1.begin(), s1.end());
                    }
                cout<<s1;
            }
        }
        
}