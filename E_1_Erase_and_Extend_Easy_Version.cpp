#include<bits/stdc++.h>
using namespace std;
#define int long long
bool f(string& s,int j){
    int i=0;
    while(j<s.size()){
        if(s[i]<s[j]) return true;
        else if(s[i]>s[j]) return false;
        i++;
        j++;
    }
    return false;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int end=n,j=n-1;
        while(j>0&&s[j]>=s[0]){
            j--;
            end--;
        }
        for(int i=1;i<=j;i++){
            if(f(s,i)){
                end=i;
                break;
            }
        }
        string s2=s.substr(0,end);
        for(int i=0;i<k;i++) cout<<s2[i%(s2.size())];
}