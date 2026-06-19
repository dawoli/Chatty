#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool f[1005][1005];
int t;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++)
	{
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		int n,m,k,d,x,y,xd,yd,cnt=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		f[x][y]=1;
		for(int i=1;i<=k;i++)
		{
			if(d==0)
			{
				if(a[x][y+1]=='.'&&x<=n&&x>0&&y+1<=m&y+1>0)
				{
					f[x][y+1]=1;
					y++;
				}
				else d++;
			}
			else if(d==1)
			{
				if(a[x+1][y]=='.'&&x+1<=n&&x+1>0&&y<=m&y>0)
				{
					f[x+1][y]=1;
					x++;
				}
				else d++;
			}
			else if(d==2)
			{
				if(a[x][y-1]=='.'&&x<=n&&x>0&&y-1<=m&y-1>0)
				{
					f[x][y-1]=1;
					y--;
				}
				else d++;
			}
			else if(d==3)
			{
				if(a[x-1][y]=='.'&&x-1<=n&&x-1>0&&y<=m&y>0)
				{
					f[x-1][y]=1;
					x--;
				}
				else d=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cnt+=f[i][j];
			}
		}
		cout<<cnt<<endl;
	}
}
