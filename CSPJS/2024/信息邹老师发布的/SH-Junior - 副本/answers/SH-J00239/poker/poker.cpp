#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool po[4][13];
char aa[2];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>aa;
        int c,n;
        if(aa[0]=='D') c=0;
        if(aa[0]=='C') c=1;
        if(aa[0]=='H') c=2;
        if(aa[0]=='S') c=3;
        if(aa[1]>='2'&&aa[1]<='9') n=aa[1]-'1';
        if(aa[1]=='A') n=0;
        if(aa[1]=='T') n=9;
        if(aa[1]=='J') n=10;
        if(aa[1]=='Q') n=11;
        if(aa[1]=='K') n=12;
        po[c][n]=1;
    }
    for(int i=0;i<4;i++)
        for(int j=0;j<13;j++)
            if(!po[i][j]) ans++;
    printf("%d",ans);
    return 0;
}
