#include<bits/stdc++.h>
using namespace std;
const int N=1e3+9;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int f[N][N],g[N][N],n,m,k,t;
int x,y,d,ans;
char c[N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans=0;
        memset(g,0,sizeof g);
        memset(f,0,sizeof f);
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        g[x][y]=1;
        for(int i=1;i<=n;i++){
            scanf("%s",c+1);
            for(int j=1;j<=m;j++){
                f[i][j]=(c[j]=='.');
            }
        }
        while(k--){
            int xx=x+dx[d];
            int yy=y+dy[d];
            if(f[xx][yy]){
                x=xx,y=yy;
                g[x][y]=1;
            }else{
                d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans+=g[i][j];
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}
