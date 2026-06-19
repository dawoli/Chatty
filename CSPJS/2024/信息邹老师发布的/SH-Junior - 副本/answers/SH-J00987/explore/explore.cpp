#include <bits/stdc++.h>
using namespace std;

int xa[5]={0,1,0,-1};
int ya[5]={1,0,-1,0};
bool flag[1005][1005];
bool ke[1005][1005];
signed main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while (t--)
	{
		memset(flag,0,sizeof(flag));
		memset(ke,0,sizeof(ke));
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		flag[x][y]=true;
		for (int i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			for (int j=0;j<s.size();j++)
			{
				if (s[j]=='.')	ke[i][j+1]=true;
				else	ke[i][j+1]=false;
			}
		}
		for (int i=1;i<=k;i++)
		{
			int nx=x+xa[d],ny=y+ya[d];
			if (nx>n || nx<1 || ny>m || ny<0 || !ke[nx][ny])
			{
				d++;
				d%=4;
			}
			else
			{
				x=nx;
				y=ny;
				flag[x][y]=true;
			}
		}
		int cnt=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				if (flag[i][j])	cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

