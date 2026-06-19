#include<bits/stdc++.h>
using namespace std;

int t;
const int N = 1e3 + 5;
char arr[N][N];
bool vis[N][N] = {0};
int movex[4] = {0, 1, 0, -1};
int movey[4] = {1, 0, -1, 0};

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin>>t;
	while(t--)
	{
		int n, m, k;
		cin>>n>>m>>k;
		int x, y, d;
		cin>>x>>y>>d;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				cin>>arr[i][j];
			}
		}
		vis[x][y] = 1;
		while(k--)
		{
			int xx = x + movex[d];
			int yy = y + movey[d];
			if(1 <= xx && xx <= n && 1 <= yy && yy <= m && arr[xx][yy] == '.')
			{
				x = xx;
				y = yy;
				vis[x][y] = 1;
			}
			else d = (d + 1) % 4;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(vis[i][j]) ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
