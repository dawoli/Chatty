#include <bits/stdc++.h>
using namespace std;
struct block{
    char ground;
    bool flag;
};
int T;
int num;
void explore(int n,int m,int k,int X,int Y,int d){
    string a;
    block jungle[100000][100000];
    for(int i=1;i<=n;i++){
            cin>>a;
        for(int j=1;j<=m;j++){
            jungle[i][j].ground=char(a[j]);
            jungle[i][j].flag=0;
        }
    }
    jungle[X][Y].flag=1;
    for(int i=1;i<=k;i++){
        if(d==0){
            Y++;
            if(Y<1||Y>m||jungle[X][Y].ground=='x'){
                Y--;
                d=(d+1)%4;
                jungle[X][Y].flag=1;
                continue;
            }
            jungle[X][Y].flag=1;
        }else if(d==1){
            X++;
            if(X<1||X>n||jungle[X][Y].ground=='x'){
                X--;
                d=(d+1)%4;
                jungle[X][Y].flag=1;
                continue;
            }
            jungle[X][Y].flag=1;
        }else if(d==2){
            Y--;
            if(Y<1||Y>m||jungle[X][Y].ground=='x'){
                Y++;
                d=(d+1)%4;
                jungle[X][Y].flag=1;
                continue;
            }
            jungle[X][Y].flag=1;
        }else if(d==3){
            X--;
            if(X<1||X>m||jungle[X][Y].ground=='x'){
                X++;
                d=(d+1)%4;
                jungle[X][Y].flag=1;
                continue;
            }
        }

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(jungle[i][j].flag==1){
                num++;
            }
        }
    }
}
int main(){
    int n,m,k,X,Y,d=0;
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n>>m>>k>>X>>Y>>d;
        explore(n,m,k,X,Y,d);
        cout<<num<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
