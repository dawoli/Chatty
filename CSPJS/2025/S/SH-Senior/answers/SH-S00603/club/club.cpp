#include<bits/stdc++.h>

using namespace std;

int t, n;
int a[100005][3];
vector<int> g[4];

bool cmpx(int x, int y) {
	return a[x][0] > a[y][0];
}

bool cmpy(int x, int y) {
	return a[x][1] > a[y][1];
}

bool cmpz(int x, int y) {
	return a[x][2] > a[y][2];
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		g[0].clear(), g[1].clear(), g[2].clear();
		scanf("%d", &n);
		int sx = 0, sy = 0, sz = 0;
		for (int i = 1; i <= n; i++)
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		cout << n << "\n";
		for (int i = 1; i <= n; i++) 
			cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << "\n";
		int tmp[100005], pos = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i][0] == a[i][1] && a[i][1] == 0 && a[i][2] != 0) 
				g[2].push_back(i), sz += a[i][2];
			else if (a[i][0] == a[i][2] && a[i][2] == 0 && a[i][1] != 0) 
				g[1].push_back(i), sy += a[i][1];
			else if (a[i][2] == a[i][1] && a[i][1] == 0 && a[i][0] != 0) 
				g[0].push_back(i), sx += a[i][0];
			else if (a[i][0] == 0 && a[i][2] > a[i][1]) 
				g[2].push_back(i), sz += a[i][2];
			else if (a[i][0] == 0 && a[i][2] <= a[i][1]) 
				g[1].push_back(i), sy += a[i][1];
			else if (a[i][1] == 0 && a[i][0] > a[i][2]) 
				g[0].push_back(i), sx += a[i][0];
			else if (a[i][1] == 0 && a[i][0] <= a[i][2]) 
				g[2].push_back(i), sz += a[i][2];
			else if (a[i][2] == 0 && a[i][1] > a[i][0]) 
				g[1].push_back(i), sy += a[i][1];
			else if (a[i][2] == 0 && a[i][1] <= a[i][0]) 
				g[0].push_back(i), sx += a[i][0];
			else tmp[++pos] = i;
		}
		if (g[0].size() > n / 2) {
			sort(g[0].begin(), g[0].end(), cmpx);
			while (g[0].size() > n / 2) {
				int x = g[0][g[0].size() - 1];
				if (a[x][1] != 0) sy += a[x][1], g[1].push_back(x);
				if (a[x][2] != 0) sz += a[x][2], g[2].push_back(x);
				sx -= a[x][0];
				g[0].pop_back();
			}
		}
		if (g[1].size() > n / 2) {
			sort(g[1].begin(), g[1].end(), cmpy);
			while (g[1].size() > n / 2) {
				int x = g[1][g[1].size() - 1];
				if (a[x][0] != 0) sx += a[x][0], g[0].push_back(x);
				if (a[x][2] != 0) sz += a[x][2], g[2].push_back(x);
				sy -= a[x][1];
				g[1].pop_back();
			}
		}
		if (g[2].size() > n / 2) {
			sort(g[2].begin(), g[2].end(), cmpz);
			while (g[2].size() > n / 2) {
				int x = g[2][g[2].size() - 1];
				if (a[x][1] != 0) sy += a[x][1], g[1].push_back(x);
				if (a[x][0] != 0) sx += a[x][0], g[0].push_back(x);
				sz -= a[x][2];
				g[2].pop_back();
			}
		}
		for (int i = 1; i <= pos; i++) {
			if (a[i][0] != 0 && a[i][0] == max(a[i][0], max(a[i][1], a[i][2])))
				g[0].push_back(i), sx += a[i][0];
			if (a[i][1] != 0 && a[i][1] == max(a[i][0], max(a[i][1], a[i][2])))
				g[1].push_back(i), sy += a[i][1];
			if (a[i][2] != 0 && a[i][2] == max(a[i][0], max(a[i][1], a[i][2])))
				g[2].push_back(i), sz += a[i][2];
		}
		while (g[0].size() > n / 2) {
			int x = g[0][g[0].size() - 1];
			sx -= a[x][0];
			if (a[x][1] > a[x][2]) sy += a[x][1];
			else sz += a[x][2];
			g[0].pop_back();
		}
		cout << sx + sy + sz << "\n";
 	}
	return 0;
}
