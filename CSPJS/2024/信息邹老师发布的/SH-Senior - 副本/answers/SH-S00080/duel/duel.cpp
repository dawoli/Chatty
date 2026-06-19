#include<bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, r[N], tag, rm, ans;
map<int, int> mp;
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &r[i]);
		mp[r[i]]++;
	}
	rm = ans = n;
	// find first > (rm-=it.second)
	// tag is to be demolished further stuff
	for (auto &it: mp) {
		int canAttack = max(it.second-tag, 0);
		tag -= it.second - canAttack;
		rm = max(0, rm-it.second);
		if (!rm) break;
		if (rm-tag >= it.second) {
			tag += it.second;
			ans -= it.second;
		} else {
			ans -= rm-tag;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
