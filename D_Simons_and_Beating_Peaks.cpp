#include<bits/stdc++.h>
using namespace std;
#define int long long
struct stree {
    int n;
    vector<int> tree;
    vector<int> arr;
    stree(vector<int> &a) {
        arr = a;
        n = a.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = start; 
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);

            int leftIndex = tree[2 * node + 1];
            int rightIndex = tree[2 * node + 2];

            tree[node] = (arr[leftIndex] >= arr[rightIndex]) 
                         ? leftIndex 
                         : rightIndex;
        }
    }
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return -1;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        int left = query(2 * node + 1, start, mid, l, r);
        int right = query(2 * node + 2, mid + 1, end, l, r);
        if (left == -1) return right;
        if (right == -1) return left;
        return (arr[left] >= arr[right]) ? left : right;
    }
    int maxi(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};
int recur(int start,int end,stree& st){
    if(end<=start) return 0;
    int idx=st.maxi(start,end);
    return min((end-idx)+recur(start,idx-1,st),(idx-start)+recur(idx+1,end,st));
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        stree st(arr);
        cout<<recur(0,n-1,st)<<endl;
    }
}