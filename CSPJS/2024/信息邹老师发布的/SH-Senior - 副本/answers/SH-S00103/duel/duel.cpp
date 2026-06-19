#include<cstdio>
#include<iostream>
#define rep(i, x, y) for (int i = (x); i <= (y); i++)
using std::cin; using std::cout;
const int maxN = 100007;
int cnt[maxN];
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	rep(i, 1, n) {
		int a;
		cin >> a;
		cnt[a]++;
	}
	int ans = 0;
	rep(i, 1, 100000)
		if (cnt[i] > ans)
			ans = cnt[i];
	cout << ans << "\n";
	return 0;
}
