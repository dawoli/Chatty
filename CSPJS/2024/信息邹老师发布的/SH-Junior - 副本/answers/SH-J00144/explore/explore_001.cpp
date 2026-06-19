#include<bits/stdc++.h>
using namespace std;

char mp[1001][1001] = {};
bool vis[1001][1001] = {0};
int T;int n,m,k;int x0,y0,d0;
void f(int x,int y,int d,int dep)
{
	
	vis[x][y] = 1;
	//cout << x << ' ' << y << ' ' << "++" << endl; 
	if (dep == k)
	{
		return;
	}
	if (d == 0)
	{
		int x1 = x,y1 = y+1;
		if (1<=x1 && x1<=n && 1<=y1 && y1<=m && mp[x1][y1] == '.')
		{
			//cout << mp[x1][y1] << dep << " " << x << " " << y << " 0t" << endl; 
			f(x1,y1,d,dep+1);
		}
		else
		{
			//cout << mp[x1][y1] << dep << " " << x << " " << y << " 0f" << endl;
			f(x,y,(d+1)%4,dep+1);
		}
	}
	else if (d == 1)
	{
		int x1 = x+1,y1 = y;
		if (1<=x1 && x1<=n && 1<=y1 && y1<=m && mp[x1][y1] == '.')
		{
			//cout << dep << " " << x << " " << y << " 1t" << endl;
			f(x1,y1,d,dep+1);
		}
		else
		{
			//cout << dep << " " << x << " " << y << " 1f" << endl;
			f(x,y,(d+1)%4,dep+1);
		}
	}
	else if (d == 2)
	{
		int x1 = x,y1 = y-1;
		if (1<=x1 && x1<=n && 1<=y1 && y1<=m && mp[x1][y1] == '.')
		{
			//cout << dep << " " << x << " " << y << " 2t" << endl;
			f(x1,y1,d,dep+1);
		}
		else
		{
			//cout << dep << " " << x << " " << y << " 2f" << endl;
			f(x,y,(d+1)%4,dep+1);
		}
	}
	else if (d == 3)
	{
		int x1 = x-1,y1 = y;
		if (1<=x1 && x1<=n && 1<=y1 && y1<=m && mp[x1][y1] == '.')
		{
			//cout << dep << " " << x << " " << y << " 3t" << endl;
			f(x1,y1,d,dep+1);
		}
		else
		{
			//cout << dep << " " << x << " " << y << " 3f" << endl;
			f(x,y,(d+1)%4,dep+1);
		}
	}
}


int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	for (int i=0;i<T;i++)
	{
		cin >> n >> m >> k;
		cin >> x0 >> y0 >> d0;
		
		for (int i=1;i<=n;i++) 
		{
			for (int j=1;j<=m;j++)
			{
				vis[i][j] = 0;
			}
		}
		for (int i=1;i<=n;i++)
		{
			cin >> mp[i]+1; 
		}
		
		f(x0,y0,d0,0);
		int sm = 0;
		for (int i=1;i<=n;i++) 
		{
			for (int j=1;j<=m;j++)
			{
				sm += vis[i][j];
				//cout << i << ' ' << j << ' ' << "==" << vis[i][j] << endl;
			}
		}
		cout << sm << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
