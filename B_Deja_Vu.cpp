#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int k=0;k<t;k++){
        int s1,s2;
        cin>>s1;
        cin>>s2;
        // vector<pair<int,int>> arr;
        vector<int> a(s1);
        // for(int i=0;i<s1;i++){
        //     int x;
        //     cin>>x;
        //     arr.push_back({x,i});
        // }
        vector<int> q;
        // sort(arr.begin(),arr.end());
        // long sum=0;

        for (int i = 0; i < s1; i++)
        {
            cin>>a[i];
        }
        
        for(int i=0;i<s2;i++){
            int x;
            cin>>x;
            if(q.size()==0||x<q[q.size()-1]){ 
                q.push_back(x);
                // sum+=pow(2,x-1);
            }
        }
        // int itr=0;
        // int check=pow(2,q[itr]);
        // int i=s1-1;
        // for(i=s1-1;i>=0;i--){
        //     if(arr[i].first<check){
        //         if(itr==q.size()-1) break;
        //         sum-=pow(2,q[itr]-1);
        //         check=pow(2,q[++itr]);
        //         i++;
        //     }
        //     else{
        //     if(arr[i].first%check==0) ans[arr[i].second]=arr[i].first+sum;
        //     else ans[arr[i].second]=arr[i].first;
        //     }
        // }
        // for(int j=i;j>=0;j--){
        //     ans[arr[j].second]=arr[j].first;
        // }

        for (int i = 0; i < q.size(); i++)
        {
            int h = 1<<q[i];
            for (int j = 0; j < s1; j++)
            {
                if(a[j]%h==0){
                    a[j]+=h/2;
                }
            }
            
        }
        

        for(int i=0;i<s1;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}