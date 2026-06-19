#include <bits/stdc++.h>
using namespace std;
int n, a [5010], cnt = 0;
bool now [5010];
void dfs (int cur) {
	if (cur == n + 1) {
		int sum = 0, maxn = -1, count = 0;
		for (int i = 1; i <= n; i ++)
			if (now [i])
				sum += a [i];
		for (int i = 1; i <= n; i ++) 
			if (now [i])
				maxn = max (maxn, a [i]);
		for (int i = 1; i <= n; i ++)
			if (now [i])
				count ++;
		if (sum > maxn * 2 && count >= 3) {
			cnt ++;
		}
		return;
	}
	dfs (cur + 1);
	now [cur] = true;
	dfs (cur + 1);
	now [cur] = false;
} 
int main () {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a [i];
	dfs (1);
	cout << cnt;
}
