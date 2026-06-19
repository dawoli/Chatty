#include <bits/stdc++.h>
#define ll long long

using namespace std; 

int t; 
int n, m, k; 
int x, y, d; 
char book[1005][1005]; 
int nt[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
bool vis[1005][1005]; 

int main()
{
	freopen("explore.in", "r", stdin); 
	freopen("explore.out", "w", stdout); 
	cin >> t; 
	while(t--)
	{
		for(int i = 1; i <= 1003; i++)
		{
			for(int j = 1; j <= 1003; j++)
			{
				vis[i][j] = false; 
			}
		}
		n = m = k = x = y = d = 0; 
		for(int i = 1; i <= 1003; i++)
		{
			for(int j = 1; j <= 1003; j++)
			{
				book[i][j] = ' '; 
			}
		}
		
		cin >> n >> m >> k; 
		cin >> x >> y >> d; 
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				cin >> book[i][j]; 
			}
		}
		
		int cnt = 1; 
		vis[x][y] = true; 
		for(int i = 1; i <= k; i++)
		{
			int nx = x + nt[d][0]; 
			int ny = y + nt[d][1]; 
			if(nx < 1 || nx > n || ny < 1 || ny > m || book[nx][ny] == 'x')
			{
				d = ((d + 1) % 4); 
				continue; 
			}
			if(!vis[nx][ny])
			{
				cnt++; 
			}
			vis[nx][ny] = true; 
			x = nx; 
			y = ny; 
		}
		
		cout << cnt << endl; 
	}
	return 0; 
}
