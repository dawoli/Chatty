#include<bits/stdc++.h>
using namespace std;
char mat[1005][1005];
int visited[1005][1005]; 
int s=0,cnt=1,n,m;
inline void dfs(int layer,int x,int y,int d)
{
	if(layer>s)
		return;
	if(d==0)
	{
		if(mat[x][y+1]!='x'&&x>=1&&x<=n&&y+1>=1&&y+1<=m)
		{
			if(visited[x][y+1]==0)
				cnt++;
			visited[x][y+1]=1;
			dfs(layer+1,x,y+1,d);
		}
		else
			dfs(layer+1,x,y,(d+1)%4);
	}
	if(d==1)
	{
		if(mat[x+1][y]!='x'&&x+1>=1&&x+1<=n&&y>=1&&y<=m)
		{
			if(visited[x+1][y]==0)
				cnt++;
			visited[x+1][y]=1; 
			dfs(layer+1,x+1,y,d);
		}
		else
			dfs(layer+1,x,y,(d+1)%4);
	}
	if(d==2)
	{
		if(mat[x][y-1]!='x'&&x>=1&&x<=n&&y-1>=1&&y-1<=m)
		{
			if(visited[x][y-1]==0)
				cnt++;
			visited[x][y-1]=1;
			dfs(layer+1,x,y-1,d);
		}
		else
			dfs(layer+1,x,y,(d+1)%4);
	}
	if(d==3)
	{
		if(mat[x-1][y]!='x'&&x-1>=1&&x-1<=n&&y>=1&&y<=m)
		{
			if(visited[x-1][y]==0)
				cnt++;
			visited[x-1][y]=1; 
			dfs(layer+1,x-1,y,d);
		}
		else
			dfs(layer+1,x,y,(d+1)%4);
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,i,x,y,d,j,l;
	scanf("%d\n",&t);
	for(l=0;l<t;++l)
	{
		scanf("%d %d %d\n",&n,&m,&s);
		scanf("%d %d %d\n",&x,&y,&d);
		memset(visited,0,sizeof(visited));
		cnt=1;
		for(i=1;i<=n;++i)
				scanf("%s\n",mat[i]+1);
		visited[x][y]=1; 
		dfs(1,x,y,d);
		printf("%d\n",cnt);
	}
	return 0;
}
