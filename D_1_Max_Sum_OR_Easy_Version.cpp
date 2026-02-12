#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int l,r;
        cin>>l>>r;
        unordered_set<int> st;
        unordered_map<int,int> mpp;
        vector<int> arr;
        int ans=0;
        for(int i=r;i>=0;i--){
            if(st.find(i)!=st.end()){
                arr.push_back(mpp[i]);
                 continue;
            }
            st.insert(i);
             int x = i;

             int bits = 0;      
             if(x!=0) bits=(int)log2(x) + 1;
             
             int mask = (1 << bits) - 1;  
             int flipped = (~x) & mask; 
             
                 ans+=i|flipped;
                 arr.push_back(flipped);
                 st.insert(flipped);
                 mpp[flipped]=i;
             } 
             
        
        cout<<2*ans<<endl;
        reverse(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}