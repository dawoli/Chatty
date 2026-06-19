#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,f,a,l[1005][1005];
string s[1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>m>>k>>x>>y>>d;
		a=1;
		s[0]=s[n+1]="  ";
		for (int j=1;j<=n;j++)
		{
			s[0]+=' ';
			s[n+1]+=' ';
			cin>>s[j];
			s[j]=' '+s[j]+' ';
			for (int t=1;t<=m;t++)
				l[j][t]=0;
		}
		l[x][y]=1;
		for (int j=1;j<=k;j++)
		{
			f=1;
			if (d==0)
			{
				if (y+1<=m&&s[x][y+1]=='.')
				{
					y++;
					f=0;
				}
			}
			else if (d==1)
			{
				if (x+1<=n&&s[x+1][y]=='.')
				{
					x++;
					f=0;
				}
			}
			else if (d==2)
			{
				if (y-1>0&&s[x][y-1]=='.')
				{
					y--;
					f=0;
				}
			}
			else
			{
				if (x-1>0&&s[x-1][y]=='.')
				{
					x--;
					f=0;
				}
			}
			if (f)
				d=(d+1)%4;
			else
			{
				if (l[x][y]==0)
				{
					l[x][y]=1;
					a++;
				}
			}
		}
		cout<<a<<endl;
	}
 }
