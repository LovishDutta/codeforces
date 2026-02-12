#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;  
    char c;  
    for(int i=0;i<t;i++){
        string str;
        vector<string> vec;
        int score=0;
        for(int k=1;k<=10;k++){
            cin>>str;
            vec.push_back(str);
        }
        for(int a=0;a<10;a++){
            for(int b=0;b<10;b++){
                if(vec[a][b]=='X'){
                    if(a==0||a==9) score+=1;
                    else if(a==1||a==8){
                        if(b==0||b==9) score+=1;
                        else score+=2;
                    }
                    else if(a==2||a==7){
                        if(b==0||b==9) score+=1;
                        else if(b==1||b==8) score+=2;
                        else score+=3;
                    }
                    else if(a==3||a==6){
                        if(b==0||b==9) score+=1;
                        else if(b==1||b==8) score+=2;
                        else if(b==2||b==7) score+=3;
                        else score+=4;
                    }
                    else if(a==4||a==5){
                        if(b==0||b==9) score+=1;
                        else if(b==1||b==8) score+=2;
                        else if(b==2||b==7) score+=3;
                        else if(b==3||b==6) score+=4;
                        else score+=5;
                    }
                    
                }
            }
        }
        cout<<score<<endl;
    }
}