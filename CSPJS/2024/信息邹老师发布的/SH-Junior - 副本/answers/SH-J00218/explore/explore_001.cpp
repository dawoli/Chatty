#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,orx,ory,dd;
char mp[1010][1010];
bool vis[1010][1010];
int tx[4] = {0,1,0,-1};
int ty[4] = {1,0,-1,0};
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	while(T --) {
		int ans = 0;
		scanf("%d %d %d",&n,&m,&k);
		scanf("%d %d %d",&orx,&ory,&dd);
		int nx = orx,ny = ory,lx,ly;
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		vis[orx][ory] = 1;
		for(int i = 1;i <= n;i = i + 1) {
			scanf("%s",mp[i] + 1);
		}
		while(k --) {
			lx = nx,ly = ny;
			nx += tx[dd];
			ny += ty[dd];
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] == '.') {
				vis[nx][ny] = 1;
			}else {
				dd = (dd + 1) % 4;
				nx = lx,ny = ly;
			}
		}
		for(int i = 1;i <= n;i = i + 1) {
			for(int j = 1;j <= m;j = j + 1) {
				if(vis[i][j] == 1) {
					ans ++; 
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
