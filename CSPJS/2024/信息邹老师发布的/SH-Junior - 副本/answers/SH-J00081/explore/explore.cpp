#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+7;
struct pos{int x,y;};
bool vis[MAXN][MAXN];
char c[MAXN][MAXN];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m,k,x0,y0,d;
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x0,&y0,&d);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
            }
        }
        pos curPos={x0,y0};
        vis[x0][y0]=1;
        while(k--){
            pos nxPos={0,0};
            if(d==0)nxPos={curPos.x,curPos.y+1};
            else if(d==1)nxPos={curPos.x+1,curPos.y};
            else if(d==2)nxPos={curPos.x,curPos.y-1};
            else nxPos={curPos.x-1,curPos.y};
            if(nxPos.x<=n&&nxPos.x>0&&nxPos.y<=m&&nxPos.y>0&&c[nxPos.x][nxPos.y]!='x'){
                vis[nxPos.x][nxPos.y]=1;
                curPos={nxPos.x,nxPos.y};
            }else{
                d=(d+1)%4;
            }
        }
        int ct=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(vis[i][j])ct++;
        printf("%d\n",ct);
        memset(vis,0,sizeof vis);
    }
    return 0;
}