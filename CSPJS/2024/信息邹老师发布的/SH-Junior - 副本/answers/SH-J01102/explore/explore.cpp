#include<bits/stdc++.h>
using namespace std;
char sz[1005][1005];
bool visited[1005][1005];
int dx[5]={0,1,0,-1};
int dy[5]={1,0,-1,0};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,i,erp,x1,y1,n,m,j,cnt=0,k,d,x,y;
	scanf("%d",&t);
	for(i=0;i<t;++i)
	{
		cnt=1;
		bool tvba=true;
		memset(visited,false,sizeof(visited));
		scanf("%d %d %d",&n,&m,&k);
		scanf("%d %d %d",&x,&y,&d);
		for(j=1;j<=n;++j)
			scanf("%s",sz[j]+1);
		for(j=0;j<k;++j)
		{
			x1=x+dx[d];
			y1=y+dy[d];
			if(sz[x1][y1]=='.'&&x1>=1&&x1<=n&&y1<=m&&y1>=1)
			{
				if(!visited[x1][y1])
					cnt++;
				visited[x1][y1]=true;
				x=x1,y=y1;
			}
			else
			{
				d=(d+1)%4;
			}
		}
		printf("%d\n",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
