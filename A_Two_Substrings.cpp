#include<bits/stdc++.h>
using namespace std;
int lessidx(vector<int>& ba,int i){
    int low=0,high=ba.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(ba[mid]>i-2) high=mid-1;
        else low=mid+1;
    }
    return high;
}
int main(){
        string s;
        cin>>s;
        vector<int> ab;
        vector<int> ba;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='A'&&s[i+1]=='B') ab.push_back(i);
            if(s[i]=='B'&&s[i+1]=='A') ba.push_back(i);
        }
        bool ans=false;
        for(int i=0;i<ab.size();i++){
            if(lower_bound(ba.begin(),ba.end(),ab[i]+2)!=ba.end()||lessidx(ba,ab[i])>=0){
                ans=true;
                break;
            }
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
}