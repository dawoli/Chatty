#include<bits/stdc++.h> 

char a[1001][1001];
bool aa[1001][1001];

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	std::cin >> T;
	int n;
	int m;
	int k;
	int x;
	int y;
	int d;
	int ans = 1;
	for (int b = 1; b <= T; b++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				aa[i][j] = 0;
			}
		}
		std::cin >> n >> m >> k;
		std::cin >> x >> y >> d;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				std::cin >> a[i][j]; 
			}
		}
		aa[1][1] = 1;
		for (int i = 1; k > 0; i++){
			if (d == 0) {
				if (a[x][y + 1] == '.' && aa[x][y + 1] == 0) {
					ans++;
					y += 1;
					aa[x][y] = 1;
				} else d = 1;
				k--;
			} else if (d == 1) {
				if (a[x + 1][y] == '.' && aa[x + 1][y] == 0) {
					ans++;
					x += 1;
					aa[x][y] = 1;
				} else d = 2;
				k--;
			} else if (d == 2) {
				if (a[x][y - 1] == '.' && aa[x][y - 1] == 0) {
					ans++;
					y -= 1;
					aa[x][y] = 1;
				} else d = 3;
				k--;
			} else {
				if (a[x - 1][y] == '.' && aa[x - 1][y] == 0) {
					ans++;
					x -= 1;
					aa[x][y] = 1;
				} else d = 0;
				k--;
			}
		}
		std::cout << ans;
		ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				a[i][j] = ' ';
			}
		}
	}
	return 0;
}

