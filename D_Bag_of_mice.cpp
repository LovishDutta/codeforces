#include<bits/stdc++.h>
using namespace std;
double dp[2][1001][1001];
double recur(bool turn,int white,int black){
    if(white<=0) return !turn;
    if(black<=0) return turn;
    if(dp[turn][white][black]!=-1) return dp[turn][white][black];
    double win=0;
    double loss=0;
    if(turn){
        win=(double)white/(double)(white+black);
        loss=((double)black/(double)(white+black))*recur(!turn,white,black-1);
    }
    else{
loss=((double)black/(double)(white+black))*(recur(!turn,white,black-2)*((double)(black-1)/(double)(white+black-1))+recur(!turn,white-1,black-1)*((double)white/(double)(white+black-1)));
    }
    return dp[turn][white][black]=win+loss;
}
int main(){
    int w,b;
    cin>>w>>b;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 1001; j++)
            for (int k = 0; k < 1001; k++)
                dp[i][j][k] = -1;
    cout << fixed << setprecision(9) << recur(true, w, b) << "\n";
    return 0;
}