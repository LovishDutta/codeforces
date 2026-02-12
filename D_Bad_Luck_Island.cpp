#include<bits/stdc++.h>
using namespace std;
double dpR[101][101][101];
double dpS[101][101][101];
double dpP[101][101][101];
double recurR(int r,int s,int p){
    if(r<=0) return 0.0;
    if(s<=0&&p<=0) return 1.0;
    if(dpR[r][s][p]!=-1) return dpR[r][s][p];
     double total = (double)r*s + (double)s*p + (double)p*r;
    double ans = 0.0;
     if (r>0 && s>0) ans += (r*(double)s / total) * recurR(r, s-1, p);
    if (r>0 && p>0) ans += (r*(double)p / total) * recurR(r-1, s, p);
    if (s>0 && p>0) ans += (s*(double)p / total) * recurR(r, s, p-1);
    return dpR[r][s][p] = ans;

}
double recurS(int r,int s,int p){
    if(s<=0) return 0;
    if(r<=0&&p<=0) return 1;
    if(dpS[r][s][p]!=-1) return dpS[r][s][p];
     double total = (double)r*s + (double)s*p + (double)p*r;
    double ans = 0.0;
    if (r>0 && s>0) ans += (r*(double)s / total) * recurS(r, s-1, p);
    if (r>0 && p>0) ans += (r*(double)p / total) * recurS(r-1, s, p);
    if (s>0 && p>0) ans += (s*(double)p / total) * recurS(r, s, p-1);
    return dpS[r][s][p] = ans;

}
double recurP(int r,int s,int p){
    if(p<=0) return 0;
    if(r<=0&&s<=0) return 1;
    if(dpP[r][s][p]!=-1) return dpP[r][s][p];
     double total = (double)r*s + (double)s*p + (double)p*r;
    double ans = 0.0;
    if (r>0 && s>0) ans += (r*(double)s / total) * recurP(r, s-1, p);
    if (r>0 && p>0) ans += (r*(double)p / total) * recurP(r-1, s, p);
    if (s>0 && p>0) ans += (s*(double)p / total) * recurP(r, s, p-1);
    return dpP[r][s][p] = ans;

}
int main(){
     int r,s,p;
    cin>>r>>s>>p;
    for (int i = 0; i < 101; i++){
        
        for (int j = 0; j < 101; j++){
            
            for (int k = 0; k < 101; k++){
                
                dpR[i][j][k] = -1;
            }
        }
    }

    cout << fixed << setprecision(12) << recurR(r,s,p) << " ";
                
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            for (int k = 0; k < 101; k++)
                dpS[i][j][k] = -1;
    cout << fixed << setprecision(12) << recurS(r,s,p) << " ";
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            for (int k = 0; k < 101; k++)
                dpP[i][j][k] = -1;
    cout << fixed << setprecision(12) << recurP(r,s,p) << " ";
}