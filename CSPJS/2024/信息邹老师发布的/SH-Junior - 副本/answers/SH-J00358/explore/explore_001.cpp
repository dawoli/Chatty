#include<bits/stdc++.h>
using namespace std;
string s;
int v[1005][1005];
int n, m, k, sum;
void dfs(int x, int y, int d)
{
	int cnt;
	if(cnt!=k)
	{
		if(d==0&&v[x][y+1]!=2)
		{
			v[x][y+1]=1;
			dfs(x,y+1,d);
		}
		else if(d==1&&v[x+1][y]!=2)
		{
			v[x+1][y]=1;
			dfs(x,y+1,d);
		}
		else if(d==2&&v[x][y-1]!=2)
		{
			v[x][y-1]=1;
			dfs(x,y+1,d);
		}
		if(d==3&&v[x-1][y]!=2)
		{
			v[x-1][y]=1;
			dfs(x,y+1,d);
		}
	}
	else{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(v[i][j]!=0)
				{
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
} 
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m>>k;
		int x, y, d;
		cin>>x>>y>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>s;
			if(s=="x")
			{
				v[j][t]=2;
			}
		}
		dfs(x,y,d);
	}
	return 0;
}

