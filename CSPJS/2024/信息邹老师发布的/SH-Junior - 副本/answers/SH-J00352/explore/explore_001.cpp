#include<bits/stdc++.h>
using namespace std;
int b[1001][1001],ti[6];
int n,m;
int check(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=m&&b[x][y]!=2)
        return 1;
    return 0;
}
int main(){
    int k,x,y,d,xn,yn,i,j,v=1,p,tn,tp;
    char di;
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>tp;
    while(v<=tp){
        cin>>n>>m>>k>>x>>y>>d;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                cin>>di;
                if(di=='x') b[i][j]=2;
            }
        }
        tn=1;
        memset(b,0,sizeof(b));
        for(p=1;p<=k;p++){
            xn=x;yn=y;
            if(d==0) yn++;
            else if(d==1) xn++;
            else if(d==2) yn--;
            else xn--;

            if(check(xn,yn)==1){
                x=xn;
                y=yn;
                b[x][y]=1;
            }
            else{
                d=(d+1)%4;
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(b[i][j]==1) tn++;
            }
        }
        ti[v++]=tn;
    }
    for(i=1;i<=tp;i++)
        cout<<ti[i]<<endl;
    return 0;
}
