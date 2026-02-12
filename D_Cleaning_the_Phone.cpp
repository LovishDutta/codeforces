#include<bits/stdc++.h>
using namespace std;
const bool comp(pair<int,int>& a,pair<int,int>& b){
    return ((double)a.first/(double)a.second)>((double)b.first/(double)b.second);
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,m;
        cin>>n>>m;
        vector<int> arr1(n);
        vector<int> arr2(n);
        for(int i=0;i<n;i++) cin>>arr1[i];
        for(int i=0;i<n;i++) cin>>arr2[i];
        vector<int> one;
        vector<int> two;
        for(int i=0;i<n;i++){
            if(arr2[i]==1) one.push_back(arr1[i]);
            else two.push_back(arr2[i]);
        }
        sort(one.rbegin(),one.rend());
        sort(two.rbegin(),two.rend());
        int i=0,j=0,ans=0;
        while(i<one.size()||j<two.size()){
            if(i<one.size()&&m<=one[i]){
                ans++;
                m-=one[i];
            }
            else if(j<two.size()&&m<=two[j]){
                ans+=2;
                m-=two[j];
            }
            else{
                
            } 
            if(m<=0) break;
        }
    }
}