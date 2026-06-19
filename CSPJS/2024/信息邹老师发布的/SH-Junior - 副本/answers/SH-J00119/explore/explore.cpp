#include<bits/stdc++.h>
using namespace std;
const int N=1010;
char a[N][N];
bool b[N][N];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,t;
		int x,y,d;
		cin>>n>>m>>t;
		cin>>x>>y>>d; 
		d=d%4;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char c;
				cin>>c;
				a[i][j]=c;
			}
		}
		b[x][y]=1;
		for(int i=1;i<=t;i++)
		{
			if(d==0)
			{
				if(a[x][y+1]=='.'&&x<=n&&x>=1&&y+1<=m&&y+1>=1)
				{
					y++;
					b[x][y]=1;
				}
				else
				{
					d++;
					d%=4;
					continue;
				}
			}
			if(d==1)
			{
				if(a[x+1][y]=='.'&&x+1<=n&&x+1>=1&&y<=m&&y>=1)
				{
					x++;
					b[x][y]=1;
				}
				else
				{
					d++;
					d%=4;
					continue;
				}
			}
			if(d==2)
			{
				if(a[x][y-1]=='.'&&x<=n&&x>=1&&y-1<=m&&y-1>=1)
				{
					y--;
					b[x][y]=1;
				}
				else
				{
					d++;
					d%=4;
					continue;
				}
			}
			if(d==3)
			{
				if(a[x-1][y]=='.'&&x-1<=n&&x-1>=1&&y<=m&&y>=1)
				{
					x--;
					b[x][y]=1;
				}
				else
				{
					d++;
					d%=4;
					continue;
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(b[i][j]==1)
				{
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
