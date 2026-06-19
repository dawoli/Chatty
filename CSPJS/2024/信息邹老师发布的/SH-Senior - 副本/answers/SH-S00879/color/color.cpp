#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int A[20];
bool B[20];

int dfs(int i, int n) {
	int ans = 0;
	if (i == n) {
		int l1 = -1, l2 = -1;
		for (int i = 1; i <= n; i++) {
//			cout << A[i] << " " << B[i] << " ";
			if (B[i]) {
				if (l1 == A[i]) ans += A[i];
//				cout << l1 << " " << A[i] << endl;
				l1 = A[i];
			} else {
				if (l2 == A[i]) ans += A[i];
//				cout << l2 << " " << A[i] << endl;
				l2 = A[i];
			}
		}
//		cout << ans << endl;
		return ans;
	}
	ans = dfs(i + 1, n);
	B[i + 1] = true;
	ans = max(ans, dfs(i + 1, n));
	B[i + 1] = false;
	return ans;
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> A[i];
		}
		cout << dfs(0, n) << endl;
	}
	return 0;
}

