#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, m;
string s;
int nx[505];
bool vis[505];
vector<int> ress;
long long ans = 0;
bool cl(string s) {
	int no_pass = 0, pass = 0;
	for (int i = 1; i <= n; i++) {
		if (no_pass >= nx[ress[i]]) no_pass++;
		else if (s[i - 1] == '0') no_pass++;
		else pass++;
	}
	if (pass >= m) return true;
	else return false; 
}
void dfs(int pos) {
	if (pos == n + 1) {
		if (cl(s)) {
			for (auto x : ress) {
				cout << x << " ";
			}
			ans = (ans + 1) % MOD;
		cout << endl;
	}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			ress.push_back(i);
			dfs(pos + 1);
			ress.pop_back();
			vis[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 
	scanf("%d %d", &n, &m);
	cin >> s;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &nx[i]);
	}
	dfs(1);
	printf("%lld", ans);
	return 0;
} 
