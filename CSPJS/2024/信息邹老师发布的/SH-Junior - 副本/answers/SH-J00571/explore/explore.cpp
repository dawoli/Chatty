#include<bits/stdc++.h>
using namespace std;
int T, n, m, k, x, y, d, ans = 1, t, cnt;
char a[110][110];
bool w[110][110];
void dfs(){
	int nx = 0, ny = 0;
	while(k >= 0 && ans < t - 1){
		if(d == 0){
			nx = x;
			ny = y + 1;
			if(ny > n || a[nx][ny] == 'x'){
				d = (d + 1) % 4;
				k--;
			}
			else{
				if(w[nx][ny] == 0) ans ++;
				x = nx, y = ny;
				k--;
				w[x][y] = 1;
			}
		}
		else if(d == 1){
			nx = x + 1;
			ny = y;
			if(nx > m || a[nx][ny] == 'x'){
				d = (d + 1) % 4;
				k--;
			}
			else{
				if(w[nx][ny] == 0) ans ++;
				x = nx, y = ny;
				k--;
				w[x][y] = 1;
			}
		}
		else if(d == 2){
			nx = x;
			ny = y - 1;
			if(ny <= 0 || a[nx][ny] == 'x'){
				d = (d + 1) % 4;
				k--;
				w[x][y] = 1;
			}
			else{
				if(w[nx][ny] == 0) ans ++;
				x = nx, y = ny;
				k--;
				w[x][y] = 1;
			}
		}
		else{
			nx = x - 1;
			ny = y;
			if(nx <= 0 || a[nx][ny] == 'x'){
				d = (d + 1) % 4;
				k--;
			}
			else{
				if(w[nx][ny] == 0) ans ++;
				x = nx, y = ny;
				k--;
			}
		}
	}
}
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	for(int i = 1;i <= T;i++){
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int j = 1;j <= n;j++){
			for(int u = 1;u <= m;u++){
				cin >> a[j][u];
				if(a[j][u] == 'x'){
					cnt ++;
				}
			}
		}
		t = n * m - cnt;
		w[x][y] = 1;
		dfs();
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
