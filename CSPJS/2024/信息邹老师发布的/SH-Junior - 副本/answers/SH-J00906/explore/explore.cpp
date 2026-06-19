#include <bits/stdc++.h>
using namespace std;
int a[1001][1001],ans[6];
bool b[1001][1001];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,v=0;
	cin>>t;
	while(t>0)
	{
		t--;
		v++;
		int n,m,k,x,y,d,xx,yy,r=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			for(int j=1;j<=m;j++)
			{
				if(s[j-1]=='.')
				{
					a[i][j]=0;
				}
				else if(s[j-1]=='x')
				{
					a[i][j]=1;
				}
				b[i][j]=0;
			}
		}
		b[x][y]=1;
		while(k>0)
		{
			k--;
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
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]==0)
			{
				x=xx;
				y=yy;
				if(b[x][y]!=1)
				{
					b[x][y]=1;
					r++;
				}
			}
			else
			{
				d=d+1;
				d%=4;
			}
		}
		ans[v]=r;
	}
	for(int i=1;i<=v;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
