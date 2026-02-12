#include<bits/stdc++.h>
using namespace std;

class LRU {
private:
    list<int> lruList;                  
    unordered_map<int, list<int>::iterator> pos;

public:
    void use(int key) {
        if (pos.find(key) != pos.end()) {
            lruList.splice(lruList.end(), lruList, pos[key]);
            return;
        }
        lruList.push_back(key);
        pos[key] = prev(lruList.end());
    }
    int getLRU() {
        if (lruList.empty()) {
            cout << "LRU list is empty!\n";
            return -1;
        }

        int key = lruList.front();     
        lruList.pop_front();         
        lruList.push_back(key);      
        pos[key] = prev(lruList.end());
        return key;
    }
};

int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,k;
        cin>>n>>k;
        LRU lru;
        vector<int> arr(n);
        map<int,int> mpp;
        for(int i=0;i<n;i++){
             cin>>arr[i];
             mpp[arr[i]]++;
        }
       for(int i=1;i<=n;i++){
        if(mpp[i]==0) lru.use(i);
       }
       for(int i=0;i<n;i++){
        lru.use(arr[i]);
       }

       for(int i=0;i<k;i++){
        int ele=lru.getLRU();
        cout<<ele<<" ";
       }
       cout<<endl;
    }
}