#include<bits/stdc++.h>
using namespace std;
int bo[5][20];
int main(){
    int n,i,j,t=0,m,k;
    char a,b;
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        if(a=='D') m=1;
        else if(a=='C') m=2;
        else if(a=='H') m=3;
        else m=4;
        if(b=='A') k=1;
        else if(b=='T') k=10;
        else if(b=='J') k=11;
        else if(b=='Q') k=12;
        else if(b=='K')k=13;
        else k=b-'0';
        bo[m][k]=1;
    }
    for(int i=1;i<=4;i++)
        for(j=1;j<=13;j++)
            if(bo[i][j]==1) t++;
    cout<<52-t;
    return 0;
}
