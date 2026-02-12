#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        int low=1;
        int high=n;
        int s1=(n*(n+1))/2;
        int s2=0;
        cout<<"2 1 "<<n<<endl;
        cout<<flush;
        cin>>s2;
        int len=s2-s1;
        if(len==1){
            while(low<=high){
                int mid=(low+high)/2;
            cout<<"1 "<<low<<" "<<mid<<endl;
            cout<<flush;
            cin>>s1;
            cout<<"2 "<<low<<" "<<mid<<endl;
            cout<<flush;
            cin>>s2;
            if(s2-s1==len) high=mid-1;
            else low=mid+1;
        }
        cout<<"! "<<low<<" "<<low<<endl;
        cout<<flush;
        }
        else{

            while(low<=high){
                int mid=(low+high)/2;
            cout<<"1 "<<low<<" "<<mid<<endl;
            cout<<flush;
            cin>>s1;
            cout<<"2 "<<low<<" "<<mid<<endl;
            cout<<flush;
            cin>>s2;
            if(s2-s1==len) high=mid;
            else if(s2-s1==0) low=mid;
            else{
                cout<<"! "<<mid+1-(s2-s1)<<" "<<mid+(len-(s2-s1))<<endl;
                cout<<flush;
                break;
            }
            }
        }
    }
}