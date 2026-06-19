#include <cstdio>
const int N=1010;
int yi[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int b[N][N];
char mp[N][N]; 
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		int my_x0,my_y0,my_d0;
		scanf("%d%d%d",&my_x0,&my_y0,&my_d0);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",mp[i]+1);
			for(int j=1;j<=m;j++)
			{
				b[i][j]=0;
			}
		}
		b[my_x0][my_y0]=1;
		int now_x=my_x0;
		int now_y=my_y0;
		int now_d=my_d0;
		for(int i=1;i<=k;i++)
		{
			int new_x=now_x+yi[now_d][0];
			int new_y=now_y+yi[now_d][1];
			int new_d=now_d;
			if(new_x>=1 && new_x<=n && new_y>=1 && new_y<=m && mp[new_x][new_y]=='.')
			{
				now_x=new_x;
				now_y=new_y;
				now_d=new_d;
			}
			else
			{
				now_d=(new_d+1)%4;
			}
			b[now_x][now_y]=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(b[i][j]==1)
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
