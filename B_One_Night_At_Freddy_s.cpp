#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m,l,a=1;
        cin>>n>>m>>l;
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++) cin>>arr[i];
        int ele=min(n+1,m);
        multiset<int> ms;
        for(int i=0;i<ele;i++) ms.insert(0);
        for(int i=1;i<=arr[n];i++){
            auto it=(ms.begin());
            int val=*it;
            ms.erase(it);
            ms.insert(val+1);           
            if(a<=n&&i==arr[a]){
                auto it=prev(ms.end());
                ms.erase(it);
                if(n-a+1>(int)ms.size()){
                     ms.insert(0);
                }
                a++;
            }
        }
        cout<<(*ms.rbegin())+(l-arr[n])<<endl;
    }
}