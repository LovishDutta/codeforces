#include<bits/stdc++.h>
using namespace std;
int countpairs(vector<int> &arr,int low,int mid,int high){
    int right=mid+1,count=0;
    for(int i=low;i<=mid;i++){
        while(right<=high&&arr[i]>(long)2*arr[right]) right++;
        count+=right-(mid+1);
    }
    return count;
}
void merge(vector<int> &arr,int low,int mid,int high){
        vector<int> temp;
        int left=low;
        int right=mid+1;
        int count=0;
        while(left<=mid&&right<=high){
            if(arr[left]>arr[right]){
                temp.push_back(arr[right]);
                right++;
            }
            else{
                temp.push_back(arr[left]);
                left++;
            }
        }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
       temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }

}

int mergesort(vector<int> &arr,int low,int high){
        int count=0;
        if(low>=high) return count;
        int mid=(high+low)/2;
        count+=mergesort(arr,low,mid);
        count+=mergesort(arr,mid+1,high);
        count+=countpairs(arr,low,mid,high);
        merge(arr,low,mid,high);
        return count;
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            arr[n-i-1]=a;
        }
        cout<<mergesort(arr,0,arr.size()-1)<<endl;
    }
}