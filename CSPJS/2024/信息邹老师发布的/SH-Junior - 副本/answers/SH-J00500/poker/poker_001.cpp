#include<bits/stdc++.h>//1
using namespace std;//2
int pok[5][14];
int pokn;
int ans=0;
int main(){//3
    freopen("poker.in","r",stdin);//4
    freopen("poker.out","w",stdout);//5
    cin>>pokn;
    for(int i=1;i<=pokn;i++){
        char npokf;
        char npokn;
        cin>>npokf>>npokn;
        int npokfn,npoknn;
        if(npokf=='D') npokfn=1;
        else if(npokf=='C') npokfn=2;
        else if(npokf=='H') npokfn=3;
        else  npokfn=4;
        if(npokn=='A') npoknn=1;
        else if(npokn=='T') npoknn=10;
        else if(npokn=='J') npoknn=11;
        else if(npokn=='Q') npoknn=12;
        else if(npokn=='K') npoknn=13;
        else npoknn=npokn-'0';
        pok[npokfn][npoknn]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(pok[i][j]==0) ans++;
        }
    }
    cout<<ans;
    return 0;//6
}//3
