#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int exx(int x,int d)
{
	if(d==1) return x+1;
	if(d==3) return x-1;
	return x;
}

int exy(int y,int d)
{
	if (d==0) return y+1;
	if (d==2) return y-1;
	return y;
}

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int abc=1;abc<=T;abc++)
	{
		bool a[1002][1002]={},b[1002][1002]={};
		int n,m,k,x,y,d,cnt=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char c;
				cin>>c;
				if(c=='x')
				{
					a[i][j]=0;
				}
				if(c=='.')
				{
					a[i][j]=1;
				}
			}
		}
		b[x][y]=1;
		for(int i=1;i<=k;i++)
		{
			int x1=exx(x,d),y1=exy(y,d);
			if(x1<1 || y1<1 || x1>n || y1>m || !a[x1][y1])
			{
				d=(d+1)%4;
			}
			else
			{
				x=x1;
				y=y1;
				b[x][y]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(b[i][j]) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
}
