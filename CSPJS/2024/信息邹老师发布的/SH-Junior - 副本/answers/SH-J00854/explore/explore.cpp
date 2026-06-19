#include <bits/stdc++.h>
using namespace std;
#define int long long 

int t;
int n, m, k, xx, yy, d;
char mp[1005][1005];
bool flag[1005][1005];

int dx[10] = {0, 1, 0, -1};
int dy[10] = {1, 0, -1, 0};

signed main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> k >> xx >> yy >> d;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				cin >> mp[i][j];
			}
		}
		int ans = 1;
		memset(flag, 0, sizeof(flag));
		flag[xx][yy] = 1;
		for(; k >= 1; k--)
		{
			int nx = xx+dx[d];
			int ny = yy+dy[d];
			while(!(nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] == '.'))
			{
				k--;
				d = (d+1) % 4;
//				cout << "turn" << endl;
				nx = xx+dx[d];
				ny = yy+dy[d];
			}
			if(k < 1) break; 
			xx = nx;
			yy = ny;
			if(!flag[xx][yy])
			{
//				cout << xx << ' ' << yy << endl;
				flag[xx][yy] = 1;
				ans++;
			}
//			if(nx >= 1 && nx <= n && ny >= 1 && ny <= m)
//			{
//				
//			}
//			else
//			{
//				d = (d+1) % 4;
//				xx = xx+dx[d];
//				yy = yy+dy[d];
//				if(!flag[xx][yy])
//				{
//					cout << xx << ' ' << yy << endl;
//					flag[xx][yy] = 1;
//					ans++;
//				}
//			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
