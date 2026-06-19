#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char a[1005][1005];
int vis[1005][1005];
const int dx[]={0,1,0,-1},
          dy[]={1,0,-1,0};

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	int T;scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		int n,m,k;scanf("%d%d%d",&n,&m,&k);
		int x,y,d;scanf("%d%d%d",&x,&y,&d);
		for(int i=1;i<=n;i++)
			scanf("%s",a[i]+1);
		vis[x][y]=1;
		while(k--){
			int nx=x+dx[d],ny=y+dy[d];
			if(nx>0&&ny>0&&nx<=n&&ny<=m&&a[nx][ny]!='x'){
				vis[nx][ny]=1;
				x=nx,y=ny;
			}else d=(d+1)%4;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j])cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
