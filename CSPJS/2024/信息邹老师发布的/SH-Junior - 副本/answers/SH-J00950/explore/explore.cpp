#include <bits/stdc++.h>
using namespace std;
int t;
int n,m,k,x,y,d;
int cnt;
char MAP[1001][1001];
void xm()
{
	if(d==0)
	{
		if(y+1<=m&&MAP[x][y+1]!='x')
		{
			y+=1;
			if(MAP[x][y]=='.')
			{
				MAP[x][y]=='A';cnt++;
			}
		}
		else d=(d+1)%4;
		return ;
	}
	if(d==1)
	{
		if(x+1<=n&&MAP[x+1][y]!='x')
		{
			x+=1;
			if(MAP[x][y]=='.')
			{
				MAP[x][y]=='A';cnt++;
			}
		}
		else d=(d+1)%4;
		return ;
	}
	if(d==2)
	{
		if(y-1>0&&MAP[x][y-1]!='x')
		{
			y-=1;
			if(MAP[x][y]=='.')
			{
				MAP[x][y]=='A';cnt++;
			}
		}
		else d=(d+1)%4;
		return ;
	}
	if(d==3)
	{
		if(x-1>0&&MAP[x-1][y]!='x')
		{
			x-=1;
			if(MAP[x][y]=='.')
			{
				MAP[x][y]=='A';cnt++;
			}
		}
		else d=(d+1)%4;
		return ;
	}
	return ;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%c",&MAP[i][j]);
		MAP[x][y]='A';cnt++;
		for(int i=1;i<=k;i++)xm();
		printf("%d",cnt);
		if(t>=1) printf("\n");
	}
	return 0;
}
