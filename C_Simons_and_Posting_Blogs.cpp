#include<bits/stdc++.h>
using namespace std;
#define int long long
set<int> st;
bool comp(const vector<int>& a, const vector<int>& b) {
    int i=0,j=0;
    while(i<a.size()&&j<b.size()){
        auto it1=st.find(a[i]),it2=st.find(b[j]);
        if(it1!=st.end()&&it2!=st.end()){
            i++;
            j++;
        }
        else if(it1!=st.end()) i++;
        else if(it2!=st.end()) j++;
        else{
            if(a[i]==b[j]){
                i++;
                j++;
                continue;
            }
            if(a[i]<b[j]) return true;
            else return false;
        }
    }
    if(i==a.size() && j==b.size()) return false;
    if(i==a.size()) return true;             
    if(j==b.size()) return false; 
    return false;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        st.clear();
        int n,a;
        cin>>n;
        vector<vector<int>> arr;
        for(int i=0;i<n;i++){
            cin>>a;
            vector<int> temp;
            vector<int> temp3(a);
            set<int> temp2;
            for(int j=a-1;j>=0;j--){
                cin>>temp3[j];
               
            }
            for(int j=0;j<a;j++){
                if(temp2.find(temp3[j])==temp2.end()){
                    temp2.insert(temp3[j]);
                    temp.push_back(temp3[j]);
                }
            }
            arr.push_back(temp);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            sort(arr.begin()+i,arr.end(),comp);
            for(int j=0;j<arr[i].size();j++){
                if(st.find(arr[i][j])==st.end()){
                    st.insert(arr[i][j]);
                    ans.push_back(arr[i][j]);
                }
            }
        }
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}