#include<bits/stdc++.h>
using namespace std;
bool vis[1002][1002], has[1002][1002];
int n, m, k, x, y, d, cnt;//сробвСио 
string s;
bool outofmp(int x, int y){
	if(x <= 0 || y <= 0 || x > n || y > m)
		return true;
	return false;
}
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		memset(vis, 0, sizeof(vis));
		memset(has, 0, sizeof(has));
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		cnt = 1, vis[x][y] = true;
		for(int i = 1; i <= n; ++i){
			cin >> s;
			for(int j = 1; j <= m; ++j)
				if(s[j - 1] == 'x')
					has[i][j] = true;
		}
		for(int i = 1; i <= k; ++i){
			if(d == 0){
				if(outofmp(x, y + 1) || has[x][y + 1])
					d = (d + 1) % 4;
				else
					y++;
			}
			else if(d == 1){
				if(outofmp(x + 1, y) || has[x + 1][y])
					d = (d + 1) % 4;
				else
					x++;
			}
			else if(d == 2){
				if(outofmp(x, y - 1) || has[x][y - 1])
					d = (d + 1) % 4;
				else
					y--;
			}
			else if(d == 3){
				if(outofmp(x - 1, y) || has[x - 1][y])
					d = (d + 1) % 4;
				else
					x--;
			}
			if(!vis[x][y])
				++cnt, vis[x][y] = true;
//			cout << x << ' ' << y << ' ' << d << endl;
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
