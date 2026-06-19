#include<bits/stdc++.h>
using namespace std;
char map1[1005][1005];
int zt[1005][1005];
int n,m,k;
int x,y,d;
int nx[4]={0,1,0,-1};
int ny[4]={1,0,-1,0};
int cnt=1;
void bfs()
{
	int dx=1,dy=1;
	cnt=1;
	zt[1][1]=1;
	for(int i=1;i<=k;i++)
	{
		if(dx+nx[d]<1||dx+nx[d]>n||dy+ny[d]<1||dy+ny[d]>m)
		{
			d++;
			d=d%4;
		}
		else
		{
			if(map1[dx+nx[d]][dy+ny[d]]=='x')
			{
				d++;
				d=d%4;
			}
			else
			{
				dx+=nx[d];
				dy+=ny[d];
				if(zt[dx][dy]==0)
				{
					cnt++;
				}				
				zt[dx][dy]=1;
				
			}
		
		}
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","W",stdout);
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j=0;j<=n;j++)
		{
			for(int z=0;z<=m;z++)
			{
				map1[j][z]=0;
				zt[j][z]=0;
			}
		}
		for(int j=1;j<=n;j++)
		{
			for(int z=1;z<=m;z++)
			{
				cin>>map1[j][z];
			}
		}
		bfs();
		cout<<cnt<<endl;
	}
	return 0;
}
