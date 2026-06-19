#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int n,m,k,x0,y0,d0,cnt;
void anss()
{
	int x=x0,y=y0,d=d0;
	a[x][y]='#';
	while(k--)
	{
		if(d==0)
		{
			if(1<=x&&x<=n&&1<=y+1&&y+1<=m&&a[x][y+1]!='x')
			{y++;a[x][y]='#';}
			else
			d=(d+1)%4;
			continue;
		}
		if(d==1)
		{
			if(1<=x+1&&x+1<=n&&1<=y&&y<=m&&a[x+1][y]!='x')
			{x++;a[x][y]='#';}
			else
			d=(d+1)%4;
			continue;
		}
		if(d==2)
		{
			if(1<=x&&x<=n&&1<=y-1&&y-1<=m&&a[x][y-1]!='x')
			{y--;a[x][y]='#';}
			else
			d=(d+1)%4;
			continue;
		}
		if(d==3)
		{
			if(1<=x-1&&x-1<=n&&1<=y&&y<=m&&a[x-1][y]!='x')
			{x--;a[x][y]='#';}
			else
			d=(d+1)%4;
			continue;
		}
	}
}
void ini()
{
	cnt=0;
	cin>>n>>m>>k>>x0>>y0>>d0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
}
void outt()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]=='#')
				cnt++;
	cout<<cnt<<endl;
}
void solve()
{
	ini();
	anss();
	outt();
}
int main()
{
	freopen("explore.in","w",stdin);
	freopen("explore.out","r",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
		solve();
	return 0;
}


