#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	map<int, int> M;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		M[x]++;
	}
	int x = 0;
	for (auto i : M) {
		x = max(x, i.second);
	}
	cout << x;
	return 0;
}

