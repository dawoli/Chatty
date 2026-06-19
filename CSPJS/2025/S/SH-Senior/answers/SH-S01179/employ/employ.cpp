#include <bits/stdc++.h>
using namespace std;
struct k {int n, v;} c [510];
bool cmp (k a, k b) {
	if (a.v != b.v) return a.v > b.v;
	else return a.n > b.n;
}
int n, m;
string s;
int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s; s = ' ' + s;
	for (int i = 1; i <= n; i ++) 
		cin >> c [i].v, c [i].n = i;
	bool flag = true;
	for (int i = 1; i <= n; i ++) {
		if (c [i].v != 1)
			flag = false;
	}
	sort (c + 1, c + n + 1, cmp);
	long long ans = 0;
	do {
		int cnt = 0, cur = 0;
		for (int i = 1; i <= n; i ++) {
			if (cur >= c [i].v || s [i] == '0') {
				cur ++; continue;
			}
			else cnt ++;
		}
		if (cnt >= m) {
			ans ++;
		}
		ans %= 998244353; 
	} while (next_permutation (c + 1, c + n + 1, cmp));
	cout << ans << endl;
} 
