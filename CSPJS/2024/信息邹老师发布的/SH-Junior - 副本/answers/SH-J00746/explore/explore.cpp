#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, m, k, q;
char a[N][N];
int nx[10] = {0, 1, 0, -1};
int ny[10] = {1, 0, -1, 0}; 
bool vst[N][N];
void f(int x, int y, int d, int step, int ans) { // 当前位置，朝向，操作数，走过的格子数 
	//cout << x << ' ' << y << ' ' << d << ' ' << step << ' ' << ans << endl;
	if(step == k) {
		cout << ans << endl;
		return;
	} 
	int xx = x + nx[d];
	int yy = y + ny[d];
	//cout << xx << ' ' << yy << endl;
	if(xx < 1 || xx > n || yy < 1 || yy > m) {
		//cout << 'a' << endl;
		f(x, y, (d+1)%4, step+1, ans);	
	}
	else if(a[xx][yy] == 'x') {
		//cout << 'b' << endl;
		f(x, y, (d+1)%4, step+1, ans);	
	}
	else if(vst[xx][yy] == true) {
		//cout << 'c' << endl;
		f(xx, yy, d, step+1, ans);
	}
	else {
		//cout << 'd' << endl;
		vst[xx][yy] = true;
		f(xx, yy, d, step+1, ans+1);
	}
}
int main () {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);
	cin >> q;
	while(q --) {
		memset(vst, 0, sizeof(vst));
		cin >> n >> m >> k;
		int x, y, d; //初始位置+方向 
		cin >> x >> y >> d;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= m; j ++) {
				cin >> a[i][j];
			}
		} 
		vst[x][y] = true;
		f(x, y, d, 0, 1);
	}
	
	return 0;
}
