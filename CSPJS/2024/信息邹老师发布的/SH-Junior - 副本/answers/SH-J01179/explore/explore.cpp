#include<iostream>
using namespace std;
int T;
void explore()
{
	int n, m, k, x, y, d;
	int a[1001][1001]={0};
	char b[1001][1001];
	cin>>n>>m>>k;
	cin>>x>>y>>d;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>b[i][j];
		}
	}
	a[x][y]=1;int count=1;
	for(int i=1;i<=k;i++)
	{
		if(d%4==0)
		{
			if(b[x][y+1]==46)
			{
				y++;
			}
			else
			{
				d++;
			}
		}
		else if(d%4==1)
		{
			if(b[x+1][y]==46)
			{
				x++;
			}
			else
			{
				d++;
			}
		}
		else if(d%4==2)
		{
			if(b[x][y-1]==46)
			{
				y--;
			}
			else
			{
				d++;
			}
		}
		else if(d%4==3)
		{
			if(b[x-1][y]==46)
			{
				x--;
			}
			else
			{
				d++;
			}
		}
		if(a[x][y]!=1)
		{
			a[x][y]=1;
			count++;
		}
	}
	cout<<count<<endl;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		explore();
	}
	return 0;
}
