#include <bits/stdc++.h>
using namespace std;
char arr[1005][1005];
bool vis[1005][1005];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	int T,n,m,k;
	int x,y,d,tx,ty;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&m,&k);
		scanf("%d %d %d",&x,&y,&d);
		for(int i=1;i<=n;i++)
			scanf("%s",arr[i]+1);
		vis[x][y]=true;
		while(k--)
		{
			tx=x+dx[d];
			ty=y+dy[d];
			if(tx<1||tx>n||ty<1||ty>m||arr[tx][ty]=='x')
			{
				d=(d+1)%4;
				continue;
			}
			vis[tx][ty]=true;
			x=tx;
			y=ty;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(vis[i][j]) cnt++;
		printf("%d\n",cnt);
		memset(vis,false,sizeof(vis));
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
