#include<bits/stdc++.h>
using namespace std;
char mat[1005][1005];
int visited[1005][1005];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,k,x,y,d,ans;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		ans=1;
		memset(visited,0,sizeof(visited));
		scanf("%d %d %d\n%d %d %d",&n,&m,&k,&x,&y,&d);
		visited[x][y]=1;
		for(int i=1;i<=n;i++)
			scanf("%s",mat[i]+1);
		for(int i=1;i<=k;i++)
		{
			if(mat[x+dx[d]][y+dy[d]]=='.')
			{
				x+=dx[d];
				y+=dy[d];
				if(!visited[x][y])
					ans++;
				visited[x][y]=1;
			}
			else
				d=(d+1)%4;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
