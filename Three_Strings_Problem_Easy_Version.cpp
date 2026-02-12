#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string p,q,r;
	    cin>>p>>q>>r;
	    int zeroone=0,onezero=0,zerop01=0,onep01=0,zerop10=0,onep10=0;
	    for(int i=0;i<n;i++){
	        if(q[i]=='0'&&r[i]=='1'){
	            zeroone++;
	            if(p[i]=='0') zerop01++;
	            else onep01++;
	        }
	        else if(q[i]=='1'&&r[i]=='0'){
	            onezero++;
	            if(p[i]=='0') zerop10++;
	            else onep10++;
	        }
	    }
	    zeroone-=min(zerop10,zerop01);
	    onezero-=min(zerop10,zerop01);
	    zeroone-=min(onep10,onep01);
	    onezero-=min(onep10,onep01);
	    cout<<max(zeroone,onezero)<<endl;
	}

}
