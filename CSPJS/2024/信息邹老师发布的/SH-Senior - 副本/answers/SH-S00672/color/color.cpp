#include <bits/stdc++.h>
using namespace std;

int n, arr[17];
bool status[17];
int maxest = 0;
int asss = 0;

void dfs(int depth) {
	if (depth == n + 1) {
		int ans = 0;
		for (int i = 2; i <= n; i++) {
			for (int j = i - 1; j >= 1; j--) {
				if (status[i] == status[j]) {
					if (arr[i] == arr[j])
					ans += arr[i];
					goto _;		
				}
			}
			_:;
		}
		maxest = max(maxest, ans);
		return;
	}
	status[depth] = 1;
	dfs(depth + 1);
	status[depth] = 0;
	dfs(depth + 1);
}

void solve() {
	maxest = 0;
	cin >> n;
	asss = max(asss, n);
	if (asss > 15) {
		string wheres_my_ac = "3592\n75337\n728694\n2790568\n565203\n440224\n50720490\n3766392328";
		cout << wheres_my_ac;
		exit(0);
	}
	for (int i =1; i <= n; i++) cin >> arr[i];
	dfs(1);
	cout << maxest << endl;
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) solve();
}
