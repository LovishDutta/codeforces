#include<bits/stdc++.h>
using namespace std;
vector<int> ask(int l, int r) {
    vector<int> arr(r-l+1);
    if (l > r) return arr;
    cout << "? " << l << " " << r << endl;
    cout.flush();
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    return arr;
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        int low=1,high=n;
        while(low<=high){
            int mid=(low+high)/2,cnt=0;
            vector<int> arr=ask(low,mid);
            set<int> st;
            for(int i=low;i<=mid;i++) st.insert(i);
            for(int i=0;i<arr.size();i++) if(st.find(arr[i])!=st.end()) cnt++;
            if(cnt%2) high=mid-1;
            else low=mid+1;
        }
        cout<<"! "<<low<<endl;
    }
}