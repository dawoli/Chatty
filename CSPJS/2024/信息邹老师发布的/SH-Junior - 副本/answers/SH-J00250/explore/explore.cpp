#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int x,y,d;
bool emap[1010][1010];
bool bmap[1010][1010];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				char here;
				cin>>here;
				bmap[j][k]=true;
				if(here=='.')
				{
					emap[j][k]=true;
				}
				else
				{
					emap[j][k]=false;
				} 
				//cout<<emap[j][k];
			}
			//cout<<endl;
		}
		int count=1;
		bmap[x][y]=false;
		for(int j=1;j<=k;j++)
		{
			int xx=x;
			int yy=y;
			int dd=d;
			if(d==0)
			{
				xx=x;
				yy=y+1;
			}
			else if(d==1)
			{
				xx=x+1;
				yy=y;
			}
			else if(d==2)
			{
				xx=x;
				yy=y-1;
			}
			else if(d==3)
			{
				xx=x-1;
				yy=y;
			}
			if((1<=xx&&xx<=n)&&(1<=yy&&yy<=m)&&(emap[xx][yy]))
			{
				x=xx;
				y=yy;
				//cout<<x<<' '<<y<<' '<<d<<endl; 
				if(bmap[x][y])
				{
				  count++;
				  bmap[x][y]=false;
				}
			}
			else
			{
				dd=(d+1)%4;
				d=dd;
			}
		}
		cout<<count<<endl;
	}
	return 0;
} 
