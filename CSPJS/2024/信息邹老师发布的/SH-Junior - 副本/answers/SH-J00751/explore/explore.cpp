#include<bits/stdc++.h>
using namespace std;
char mat[1005][1005];
int visited[1005][1005];
const int dx[5]={0,1,0,-1};
const int dy[5]={1,0,-1,0};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(visited,0,sizeof(visited));
		int n,m,k,x,y,d,ans=1;
		scanf("%d%d%d\n%d%d%d\n",&n,&m,&k,&x,&y,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",mat[i]+1);
		}
		visited[x][y]=1;
		while(k>0)
		{
			while(1)
			{
				if(k<=0)
					break;
				k--;
				int tx=x+dx[d%4],ty=y+dy[d%4];
				if(tx<1||tx>n||ty<1||ty>m||mat[tx][ty]=='x')
				{
					d++;
					continue;
				}
				else
				{
					x=tx,y=ty;
					if(!visited[x][y])
						ans++;
					visited[x][y]=1;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
