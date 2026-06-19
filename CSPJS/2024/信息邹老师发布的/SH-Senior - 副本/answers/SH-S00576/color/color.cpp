#include<bits/stdc++.h>
using namespace std;

/*dp?*/

int t, n, a[200002];
int mx, sc, c[200002];

void dfs(int d) {
	if (d==n || d > 32) {
		mx = max(mx, sc);
		return;
	}
	int ds = 0;
	c[d] = 1;
	for (int i=d-1; i>=0; i--) {
		if (c[i] == c[d]) {
			if (a[i] == a[d]) ds = a[d];
			break;
		}
	}
	sc += ds;
	dfs(d+1);
	sc -= ds;
	
	c[d] = 0;
	for (int i=d-1; i>=0; i--) {
		if (c[i] == c[d]) {
			if (a[i] == a[d]) ds = a[d];
			break;
		}
	}
	sc += ds;
	dfs(d+1);
	sc -= ds;
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		mx = sc = 0;
		dfs(0);
		cout << mx << '\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

