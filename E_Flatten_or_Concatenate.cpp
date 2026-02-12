#include<bits/stdc++.h>
using namespace std;
#define int long long
long long ask(int l, int r) {
    if (l > r) return 0;
    cout << "? " << l << " " << r << endl;
    cout.flush();
    long long s;
    cin >> s;
    return s;
}

signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        int low=1,high=n;
        int sum=ask(low,high);
        while(low<high){
            int l2=low;
            int h2=high;
            sum/=2;
            while(l2<=h2){
                int mid=(l2+h2)/2;
                int s=ask(low,mid);
                if(sum>s) l2=mid+1;
                else h2=mid-1;
            }
            if(l2-low+1>high-l2) low=l2+1;
            else high=l2;
        }
        int ans=ask(low,low);
         cout << "! " << ans << endl;
         cout.flush();
    }
}