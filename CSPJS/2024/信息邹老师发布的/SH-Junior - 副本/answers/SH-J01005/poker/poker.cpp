#include<bits/stdc++.h>
using namespace std;
int a[10][20];
int main(){

    //freopen("poker.in","r",stdin);
    //freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char x,y;
        cin>>x>>y;
        if(x=='D'){
            if(y=='T'){
                a[1][10]++;
            }else if(y=='J'){
                a[1][11]++;
            }else if(y=='Q'){
                a[1][12]++;
            }else if(y=='K'){
                a[1][13]++;
            }else if(y=='A'){
                a[1][1]++;
            }else{
                a[1][y-'0']++;
            }
        }
        if(x=='C'){
            if(y=='T'){
                a[2][10]++;
            }else if(y=='J'){
                a[2][11]++;
            }else if(y=='Q'){
                a[2][12]++;
            }else if(y=='K'){
                a[2][13]++;
            }else if(y=='A'){
                a[2][1]++;
            }else{
                a[2][y-'0']++;
            }
        }
        if(x=='H'){
            if(y=='T'){
                a[3][10]++;
            }else if(y=='J'){
                a[3][11]++;
            }else if(y=='Q'){
                a[3][12]++;
            }else if(y=='K'){
                a[3][13]++;
            }else if(y=='A'){
                a[3][1]++;
            }else{
                a[3][y-'0']++;
            }
        }
        if(x=='S'){
            if(y=='T'){
                a[4][10]++;
            }else if(y=='J'){
                a[4][11]++;
            }else if(y=='Q'){
                a[4][12]++;
            }else if(y=='K'){
                a[4][13]++;
            }else if(y=='A'){
                a[4][1]++;
            }else{
                a[4][y-'0']++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}

