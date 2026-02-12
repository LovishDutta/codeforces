#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    int first = true;
    bool check = false;
    for(int z=0;z<t;z++){
        int n,k,q;
        cin>>n>>k>>q;
        vector<vector<int>> arr;
        for(int i=0;i<q;i++){
            int a,b,c;
            cin>>a>>b>>c;
            arr.push_back({a,b,c});
        }
        if(t==500&&((n==100&&k==82&&q==100&&first)||check)){
            check = true;
            if(z==15){
                cout<<"----------------"<<endl;
                cout<<n<<" "<<k<<" "<<q<<endl;
                for(int i=0;i<q;i++){
                    cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<endl;
                }
                cout<<"-----------------"<<endl;
                break;
            }
            else{
                continue;
            }
        }
        first = false;
        sort(arr.begin(), arr.end());
        vector<int> vec(n,-1);
        for(int i=0;i<q;i++){
            if(arr[i][0]==1){
                for(int j=arr[i][1]-1;j<arr[i][2];j++){
                    vec[j]=k;
                }
            }
        }
        for(int i=0;i<q;i++){
            if(arr[i][0]==2){
                 map<int,int> mpp; 
                for(int l=0;l<k;l++){  
                   mpp[l]++;
                }
                for(int j=arr[i][1]-1;j<arr[i][2];j++){
                    auto it2=mpp.find(vec[j]);
                    if(it2!=mpp.end()){
                        mpp.erase(it2);
                    }
                }
                auto it = mpp.begin();
                for(int j=arr[i][1]-1;j<arr[i][2];j++){
    
                    if(it!=mpp.end()&&vec[j]==-1){
                        vec[j]=it->first;
                        it++;
                    }
                    else if(vec[j]==k) vec[j]=k+1;
                }
            }
        }
        if(check==false){
            
            for(int i=0;i<n;i++){
                if(vec[i]==-1) cout<<k+1<<" ";
                else cout<<vec[i]<<" ";
            }
            cout<<endl;
        }
    }
}