#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        int part=0;
        map<int,int> mpp;
        map<int,int> mpp2;

        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
            mpp2[arr[i]]++;
            if(mpp.size()==mpp2.size()){
               part++;
                mpp2.clear();
            }
        }
        cout<<part<<endl;
        
    }
}