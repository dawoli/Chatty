#include<bits/stdc++.h>
using namespace std;

int T;
int n, m, k;
int x, y, d;
char a[1009][1009];
bool isv[1009][1009];
int ans = 1, tms;

int dfs(int x, int y, int d){
	if(tms == k) return ans;
	tms ++;
	if(d == 0 && x >= 1 && y + 1 >= 1 && x <= n && y + 1 <= m && a[x][y + 1] == '.'){
		dfs(x, y + 1, d);
		if(isv[x][y + 1] == false) ans ++;
		isv[x][y + 1] = true;
	}
	else if(d == 1 && x + 1 >= 1 && y >= 1 && x + 1 <= n && y <= m && a[x + 1][y] == '.'){
		dfs(x + 1, y, d);
		if(isv[x + 1][y] == false) ans ++;
		isv[x + 1][y] = true;
	}
	else if(d == 2 && x >= 1 && y - 1 >= 1 && x <= n && y - 1 <= m && a[x][y - 1] == '.'){
		dfs(x, y - 1, d);
		if(isv[x][y - 1] == false) ans ++;
		isv[x][y - 1] = true;
	}
	else if(d == 3 && x - 1 >= 1 && y >= 1 && x - 1 <= n && y <= m && a[x - 1][y] == '.'){
		dfs(x - 1, y, d);
		if(isv[x - 1][y] == false) ans ++;
		isv[x - 1][y] = true;
	}
	else{
		dfs(x, y, (d + 1) % 4);
	}
}

int main(){	
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	while(T --){
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= m; j ++){
				cin >> a[i][j];
			}
		}
		if(k == 1){
			if(d == 0){
				if(x < 1 || y + 1 < 1 || x > n || y + 1 > m || a[x][y + 1] == 'x'){
					cout << 1 << endl;
				}
				else cout << 2 << endl;
			}
			else if(d == 1){
				if(x + 1 < 1 || y < 1 || x + 1 > n || y > m || a[x + 1][y] == 'x'){
					cout << 1 << endl;
				}
				else cout << 2 << endl;
			}
			else if(d == 2){
				if(x < 1 || y - 1 < 1 || x > n || y - 1 > m || a[x][y - 1] == 'x'){
					cout << 1 << endl;
				}
				else cout << 2 << endl;
			}
			else if(d == 3){
				if(x - 1 < 1 || y < 1 || x - 1 > n || y > m || a[x - 1][y] == 'x'){
					cout << 1 << endl;
				}
				else cout << 2 << endl;
			}
		}
		else{
			dfs(x, y, d);
			cout << ans << endl;
		}
	}
	
	return 0;
}
