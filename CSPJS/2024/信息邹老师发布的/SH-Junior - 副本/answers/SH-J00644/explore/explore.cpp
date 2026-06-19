#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
bool vis[1010][1010];
char mp[1010][1010]; 
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n,m,k;
		cin >> n >> m >> k;
		int x,y,d;
		cin >> x >> y >> d;
		for(int i = 1;i <= n;i++) cin >> mp[i] + 1;
		vis[x][y] = true;
		while(k--)
		{
			int gx = x,gy = y;
			if(d == 0) gy++;
			else if(d == 1) gx++;
			else if(d == 2) gy--;
			else gx--;
			if(gx < 1 || gx > n || gy < 1 || gy > m || mp[gx][gy] == 'x') d = (d + 1) % 4;
			else
			{
				x = gx;
				y = gy;
				vis[x][y] = true;
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) ans += vis[i][j];
		cout << ans << endl;
		memset(vis,false,sizeof(vis));
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
