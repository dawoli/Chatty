#include <bits/stdc++.h>

using namespace std;

freopen("explore.in","r",stdin);
freopen("explore.out","w",stdout);

int t;
int n,m,k,xx,yy,dd;
int num=0;
char b[1001][1001];
bool vis[1001][1001];
void dfs(int x,int y,int d,int kk)
{
    if(kk==0){
        return;
    }
    int xp=x,yp=y;
    if(d==0){
        yp++;
    }
    if(d==1){
        xp++;
    }
    if(d==2){
        yp--;
    }
    if(d==3){
        xp--;
    }
    if(xp>=1&&xp<=n&&yp>=1&&yp<=m&&b[xp][yp]!='x'){
        if(vis[xp][yp]==false){
            vis[xp][yp]=true;
            num++;
        }
        dfs(xp,yp,d,kk-1);
    }
    else{
        dfs(x,y,(d+1)%4,kk-1);
    }
}
int main()
{
    cin>>t;
    for(int a=0;a<t;a++){
        cin>>n>>m>>k;
        cin>>xx>>yy>>dd;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>b[i][j];
                vis[i][j]=false;
            }
        }
        vis[xx][yy]=true;
        num=1;
        dfs(xx,yy,dd,k);
        cout<<num<<endl;
    }
    return 0;
}
