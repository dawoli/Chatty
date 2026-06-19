#include <bits/stdc++.h>
using namespace std;
struct Student {
	int a1, a2, a3, stat, pr, ma;
} a[100010];
int t, n, cnt[4], ans[5], prs[100010];
inline void init(Student &stu) {
	cin >> stu.a1 >> stu.a2 >> stu.a3;
	int m1 = max(stu.a2, stu.a3), m2 = max(stu.a1, stu.a3), m3 = max(stu.a1, stu.a2), st = 0, m = max(max(m1, m2), m3);
	stu.ma = m;
	stu.pr = m - min(min(m1, m2), m3);
	if(m == stu.a1) st = 1;
	else if(m == stu.a2) st = 2;
	else st = 3;
	++cnt[st];
	stu.stat = st;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for(int i = 0; i < t; ++i) {
		cin >> n;
		for(int j = 1; j <= n; ++j) init(a[j]);
		int ov = 0;
		if(cnt[1] > n / 2) ov = 1;
		else if(cnt[2] > n / 2) ov = 2;
		else if(cnt[3] > n / 2) ov = 3;
		cnt[ov] -= n / 2;
		int *p = prs;
		for(int j = 1; j <= n; ++j){
			ans[i] += a[j].ma;
			if(a[j].stat == ov) *(p++) = a[j].pr;
		}
		sort(prs, p);
		for(int j = 0; j < cnt[ov]; ++j) ans[i] -= prs[j];
		cnt[1] = 0;
		cnt[2] = 0;
		cnt[3] = 0;
	}
	for(int i = 0; i < t; ++i) cout << ans[i] <<'\n';
	return 0;
}
