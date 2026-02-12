#include<bits/stdc++.h>
using namespace std;
int ask(int l, int r) {
    int a=0;
    cout << "? " << l << " " << r << endl;
    cout.flush();
    cin>>a;
    return a;
}
int main(){
    int n,cur=1,next=2;
    cin>>n;
    vector<int> arr(n+1,n);
    while(next<=n){
        int a=ask(cur,next);
        int b=ask(next,cur);
        if(b>a){
            arr[next]=b;
            next++;
        }
        else{
            arr[cur]=a;
            cur=next;
            next++;
        }
    }
    cout<<"! ";
    for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
    cout.flush();
}