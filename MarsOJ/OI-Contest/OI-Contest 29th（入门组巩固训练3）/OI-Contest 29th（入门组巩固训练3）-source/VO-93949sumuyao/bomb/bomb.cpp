#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int A[1005][1005];
pair<int, int> B[1005][1005];

int getint() {
	int ans = 0;
	int c = getchar();
	while (!isdigit(c)) {
		c = getchar();
	}
	while (isdigit(c)) {
		ans = ans * 10 + c - '0';
		c = getchar();
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("bomb.in", "r", stdin);
	freopen("bomb.out", "w", stdout);
	int t = getint() + 1;
	while (--t) {
		int n = getint(), m = getint();
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				B[i][j] = make_pair(1e9, 1e9);
				int c = getchar();
				while (c != '.' && c != '$' && c != '*') {
					c = getchar();
				}
				if (c == '.') {
					A[i][j] = 0;
				} else if (c == '$') {
					A[i][j] = 1;
				} else {
					A[i][j] = 2;
				}
			}
		}
		B[1][1] = make_pair(0, 0);
		queue<pair<int, int> > *Q1 = new queue<pair<int, int> >(), *Q2 = new queue<pair<int, int> >();
		(*Q1).push(make_pair(1, 1));
		while (true) {
			if ((*Q1).empty()) {
				if ((*Q2).empty()) {
					break;
				}
				swap(Q1, Q2);
			}
			int x = (*Q1).front().first, y = (*Q1).front().second;
			(*Q1).pop();
			if (x > 1 && A[x - 1][y] != 2) {
				pair<int, int> cost = B[x][y];
				if (A[x - 1][y]) ++cost.first;
				++cost.second;
				if (cost < B[x - 1][y]) {
					B[x - 1][y] = cost;
					if (A[x - 1][y]) (*Q2).push(make_pair(x - 1, y));
					else (*Q1).push(make_pair(x - 1, y));
				}
			}
			if (y > 1 && A[x][y - 1] != 2) {
				pair<int, int> cost = B[x][y];
				if (A[x][y - 1]) ++cost.first;
				++cost.second;
				if (cost < B[x][y - 1]) {
					B[x][y - 1] = cost;
					if (A[x][y - 1]) (*Q2).push(make_pair(x, y - 1));
					else (*Q1).push(make_pair(x, y - 1));
				}
			}
			if (x < n && A[x + 1][y] != 2) {
				pair<int, int> cost = B[x][y];
				if (A[x + 1][y]) ++cost.first;
				++cost.second;
				if (cost < B[x + 1][y]) {
					B[x + 1][y] = cost;
					if (A[x + 1][y]) (*Q2).push(make_pair(x + 1, y));
					else (*Q1).push(make_pair(x + 1, y));
				}
			}
			if (y < m && A[x][y + 1] != 2) {
				pair<int, int> cost = B[x][y];
				if (A[x][y + 1]) ++cost.first;
				++cost.second;
				if (cost < B[x][y + 1]) {
					B[x][y + 1] = cost;
					if (A[x][y + 1]) (*Q2).push(make_pair(x, y + 1));
					else (*Q1).push(make_pair(x, y + 1));
				}
			}
		}
		cout << B[n][m].first << " " << B[n][m].second << "\n";
	}
	return 0;
}
 
