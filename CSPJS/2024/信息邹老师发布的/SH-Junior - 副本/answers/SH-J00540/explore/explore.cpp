#include<bits/stdc++.h>
using namespace std;
int T, n, m, k, mp[1005][1005], vst[1005][1005], mpcnt;
int x, y, d; 
bool check(int xx, int yy)
{
	if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && mp[xx][yy] == 0) return 1;
	else return 0;
} 
int main()
{
	cin.tie(0), cout.tie(0);
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin>>T;
	for(int g = 1; g <= T; g++)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		mpcnt = 1;
		vst[x][y] = g;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				char c;
				cin>>c;
				if(c == 'x') mp[i][j] = 1;
				else mp[i][j] = 0;
			}
		}
		while(k--)
		{
			if(d == 0 && check(x, y + 1))
			{
				y++;
				if(vst[x][y] != g) mpcnt++;
				vst[x][y] = g;
			}
			else if(d == 1 && check(x + 1, y))
			{
				x++;
				if(vst[x][y] != g) mpcnt++;
				vst[x][y] = g;
			}
			else if(d == 2 && check(x, y - 1))
			{
				y--;
				if(vst[x][y] != g) mpcnt++;
				vst[x][y] = g;
			} 
			else if(d == 3 && check(x - 1, y))
			{
				x--;
				if(vst[x][y] != g) mpcnt++;
				vst[x][y] = g;
			}
			else d = (d + 1) % 4;
		}
		cout<<mpcnt<<endl;
	}
	return 0;
}
