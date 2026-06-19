#include<iostream>
#include<stdio.h>
using namespace std;
char a[1005][1005];
bool v[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void memset(int n,int m)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			v[i][j]=false;
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int g=1;g<=T;g++)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		int x,y;
		scanf("%d%d",&x,&y);
		int d;
		scanf("%d",&d);
		memset(n,m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		v[x][y]=true;
		for(int i=1;i<=k;i++)
		{
			int xx=x+dx[d],yy=y+dy[d];
			if(a[xx][yy]=='x'||((xx<1||xx>n)||(yy<1||yy>m)))
			{
				d=(d+1)%4;
			}
			else
			{
				
				v[xx][yy]=true;
				x=xx,y=yy;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(v[i][j])
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

