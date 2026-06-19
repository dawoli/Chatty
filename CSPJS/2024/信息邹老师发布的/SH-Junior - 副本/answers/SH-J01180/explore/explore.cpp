#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, m, k, x, y, d, cnt;
string s[1145];
bool vis[1145][1145];
void go(int &x, int &y, int &d){
	int xx, yy;
	if(d == 0){
		xx = x;
		yy = y + 1;
	} else if(d == 1){
		xx = x + 1;
		yy = y;
	} else if(d == 2){
		xx = x;
		yy = y - 1;
	} else if(d == 3){
		xx = x - 1;
		yy = y;
	}
	if(s[xx][yy] == 'x' || xx > n || xx <= 0 || yy > m || yy <= 0){
		d = (d + 1) % 4;
	} else{
		x = xx;
		y = yy;
	}
}
signed main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while(t--){
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		vis[x][y] = 1;
		for(int i = 1; i <= n; i++){
			cin >> s[i];
			s[i] = " " + s[i];
		}
		while(k--){
			go(x, y, d);
			vis[x][y] = 1;
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(vis[i][j]){
					cnt++;
				}
			}
		}
		printf("%lld\n", cnt);
	}
	return 0;
}
