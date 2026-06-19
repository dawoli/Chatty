#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, x;
string s;
bool used[1005] = {};
int p[1005], c[1005], list[1005];
void dfs(const int progress, const int current_c, const int current_index, const int sum) {
	if (used[current_index]) return;
	if (progress >= n) {
		if(sum>= m) {
			x++;
			x%=998244253;
		}
		return;
	}
	used[current_index]=1;
	for (int i = 0; i < n; ++i) {
		dfs(progress + 1, current_c + (c[i]==1?0:1), i, sum + c[i]);
	}
	used[current_index]=0;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i =0; i<n;++i)p[i]=s[i]-'0';
	for(int i=0;i<n;++i) cin >> c[i];
	dfs(-1, 0, 0, 0);
	cout << x << endl;
	return 0;
}
