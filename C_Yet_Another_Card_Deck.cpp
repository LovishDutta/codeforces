#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n;    
    cin>>q;    
    deque<int> cards(n);
    vector<int> queries(q);
    for(int i=0;i<n;i++){
        cin>>cards[i];
    }
    for(int i=0;i<q;i++){
        cin>>queries[i];
    }
    for(int i=0;i<q;i++){
        int cnt=1;
        for(int j=0;j<n;j++){
            if(queries[i]==cards[j]){
                cout<<cnt<<" ";
               if(cnt>1){
                   int x=cards[j];
                    cards.erase(cards.begin()+j);
                    cards.push_front(x);
               }
                break;
            }
            cnt++;
        }
    }
}