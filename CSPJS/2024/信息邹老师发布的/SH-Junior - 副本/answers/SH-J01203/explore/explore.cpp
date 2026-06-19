#include<bits/stdc++.h>
using namespace std;
int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0};
int s[1005][1005];
int visited[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,i,j,k1;
	int n,m,k;
	int x,y,d;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		int l=1;
		memset(visited,0,sizeof(visited));
		scanf("%d %d %d",&n,&m,&k);
		scanf("%d %d %d",&x,&y,&d);
		for(j=1;j<=n;j++)
		{
			getchar();
			for(k1=1;k1<=m;k1++)
				scanf("%c",&s[j][k1]);
		}
		visited[x][y]=1;
		int x1,y1;
		for(j=1;j<=k;j++)
		{
			x1=x+dx[d];
			y1=y+dy[d];
			if(x1<1||x1>n||y1<1||y1>m||s[x1][y1]=='x')
			{
				d=(d+1)%4;
				continue;
			}
			if(!visited[x1][y1])
				l++;
			visited[x1][y1]=1;
			x=x1;
			y=y1;
		}
		printf("%d\n",l);
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
