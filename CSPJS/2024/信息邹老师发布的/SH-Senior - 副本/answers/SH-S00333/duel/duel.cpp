#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
struct Monster {
	int a, d;
}m[MAXN];
int n, cnt[MAXN], MAXR=0, ans=0;
bool cmp (Monster a, Monster b) {
	return a.d>b.d;
}
int main () {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i=1; i<=n; i++) {
		int r;
		cin >> r;
		m[i].a=m[i].d=r;
		cnt[r]++;
		MAXR=max(MAXR, r);
	}
	for (int i=1; i<=MAXR; i++) ans=max(ans, cnt[i]);
	cout << ans << "\n";
}
