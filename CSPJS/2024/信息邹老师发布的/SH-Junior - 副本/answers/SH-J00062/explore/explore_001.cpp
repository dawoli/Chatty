#include<bits/stdc++.h>
using namespace std;

int T,n,m,k,d,x,y;
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
char a[1001][1001];
bool book[1001][1001];

int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	for(int i = 1;i <= T;i++) {
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		memset(book,false,sizeof(book));
		book[x][y] = true;
		for(int i = 1;i <= n;i++) 
			scanf("%s",a[i] + 1);
		for(int i = 1;i <= k;i++) {
			if(dx[d] + x <= n && dx[d] + x > 0 && dy[d] + y <= m && dy[d] + y > 0 && a[dx[d] + x][dy[d] + y] == '.')
				x += dx[d],y += dy[d],book[x][y] = true;
			else 
				d = (d + 1) % 4;
		}
		int ans = 0;
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
				if(book[i][j])
					ans++;
		printf("%d\n",ans);
	}
	return 0;
}
