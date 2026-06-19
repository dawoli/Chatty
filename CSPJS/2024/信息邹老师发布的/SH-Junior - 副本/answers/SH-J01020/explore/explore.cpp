#include<bits/stdc++.h>
using namespace std;
char c[1005][1005];
bool b[1005][1005];
int n,m;
void dfs(int step,int x,int y,int dir)
{
	b[x][y]=1;
	if(step==0) return;
	
	if(dir==0)
	{
		if(c[x][y+1]=='.')
		{
			if(c[x][y+2]=='.') dfs(step-1,x,y+1,dir);
			else dfs(step-1,x,y+1,1);
		}
		else dfs(step-1,x,y,1);
	}
	if(dir==1)
	{
		if(c[x+1][y]=='.')
		{
			if(c[x+2][y]=='.') dfs(step-1,x+1,y,dir);
			else dfs(step-1,x+1,y,2);
		}
		else dfs(step-1,x,y,2);
	}
	if(dir==2)
	{
		if(y>1&&c[x][y-1]=='.')
		{
			if(y>2&&c[x][y-2]=='.') dfs(step-1,x,y-1,dir);
			else dfs(step-1,x,y-1,3);
		}
		else dfs(step-1,x,y,3);
	}
	if(dir==3)
	{
		if(x>1&&c[x-1][y]=='.')
		{
			if(x>2&&c[x-2][y]=='.') dfs(step-1,x-1,y,dir);
			else dfs(step-1,x-1,y,0);
		}
		else dfs(step-1,x,y,0);
	}
	return;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		memset(b,0,sizeof(b));
		memset(c,' ',sizeof(c));
		int ste,x,y,dir;
		cin >> n >> m >> ste >> x >> y >> dir;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin >> c[i][j];
			}
		}
		dfs(ste,x,y,dir);
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(b[i][j]==1) cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
