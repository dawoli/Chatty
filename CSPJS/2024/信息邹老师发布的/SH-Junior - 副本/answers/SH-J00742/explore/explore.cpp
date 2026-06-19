#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
bool mp[N][N];
int tx[4] = {0,1,0,-1};
int ty[4] = {1,0,-1,0};
bool vis[N][N];
void run() {
	int n,m,k;
	int x,y,d;
	string s;
	cin >> n >> m >> k >> x >> y >> d;
	for(int i = 1;i <= 1000;i++) {
		for(int j = 1;j <= 1000;j++) {
			vis[i][j] = 0;
		}
	}
	for(int i = 1;i <= n;i++){
		cin >> s;
		for(int j = 1;j <= m;j++) {
			if(s[j-1] == 'x') {
				mp[i][j] = 1;
			} else {
				mp[i][j] = 0;
			}
		}
	}
	vis[x][y] = 1;
	int cnt = 0;
	for(int i = 1;i <= k;i++) {
		int nx = x+tx[d],ny = y+ty[d];
		if(mp[nx][ny] || nx < 1 || nx > n || ny < 1 || ny > m) {
			d = (d+1) % 4;
		} else {
			x = nx;
			y = ny;
			vis[x][y] = 1;
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(vis[i][j]) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >> t;
	while(t--) {
		run();
	}
	return 0;
}
