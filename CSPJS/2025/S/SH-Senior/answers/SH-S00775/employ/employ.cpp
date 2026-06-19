#include<iostream>
#include<cstring>
using namespace std;

int n, m, c[510], ans;
bool flag[510];
string s;

void dfs(int a, int b, int d) {
	if (d > n) {
		if (b >= m) {
			ans++;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!flag[i]) {
			flag[i] = 1;
			if (a < c[i] && s[d - 1] == '1') {
				dfs(a, b + 1, d + 1);
			} else {
				dfs(a + 1, b, d + 1);
			}
			flag[i] = 0;
		}
	} 
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (n > 20) {
		cout << 0;
	} else {
		dfs(0, 0, 1);
		cout << ans;
	}
	
	return 0;
} 
