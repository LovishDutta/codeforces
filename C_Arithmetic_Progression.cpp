#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<-1;
        return 0;
    }
    
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    if(n==2){
        if(arr[1]==arr[0]){
            cout<<1<<endl;
            cout<<arr[0];
        }
        else if((arr[1]-arr[0])%2==0){
            cout<<3<<endl;
            int d=(arr[1]-arr[0]);
            cout<<arr[0]-d<<" ";
            cout<<arr[0]+d/2<<" ";
            cout<<arr[1]+d<<" ";
        }
        else{
            cout<<2<<endl;
            int d=(arr[1]-arr[0]);
            cout<<arr[0]-d<<" ";
            cout<<arr[1]+d<<" ";
        }
         return 0;
    }
    vector<int> diff(2,-1);
    vector<int> cnt(2,0);
    int idx1=-1,idx2=-1;
    for(int i=0;i<n-1;i++){
        int a=arr[i+1]-arr[i];
        if(diff[0]==a) cnt[0]++;
        else if(diff[1]==a) cnt[1]++;
        else{
            if(diff[0]==-1){
                diff[0]=a;
                cnt[0]++;
                idx1=i;
            }
            else if(diff[1]==-1){
                diff[1]=a;
                cnt[1]++;
                idx2=i;
            }
            else{
                cout<<0;
                return 0;
            }
        }
    }
    if(diff[1]==-1){
        if(diff[0]==0){
            cout<<1<<endl;
            cout<<arr[0];
            return 0;
        }
        cout<<2<<endl;
        cout<<arr[0]-diff[0]<<" ";
        cout<<arr[n-1]+diff[0];
        return 0;
    }
    if(diff[1]<diff[0]){
        swap(diff[0],diff[1]);
        swap(cnt[0],cnt[1]);
        swap(idx1,idx2);
    }
    if(diff[1]==2*diff[0]&&cnt[1]==1){
        cout<<1<<endl;
        cout<<arr[idx2]+diff[0];
        return 0;
    }
    else cout<<0;
}