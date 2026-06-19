#include <bits/stdc++.h>

using namespace std;

inline int read() {
	int res = 0, x = getchar();
	while (x < '0' || '9' < x) x = getchar();
	while ('0' <= x && x <= '9') res = res * 10 + x - '0', x = getchar();
	return res;
}

int t, n, cnt[3];
long long ans;

struct node {
	int x, y, z;
} a[100005];

vector<node> qu[4];

inline int fst1(const node &x) {
	return max(x.x, max(x.y, x.z));
}

inline int snd1(const node &x) {
	if (min(x.y, x.z) <= x.x && x.x <= max(x.y, x.z)) return x.x;
	else if (min(x.x, x.z) <= x.y && x.y <= max(x.x, x.z)) return x.y;
	return x.z;
}

inline int ird1(const node &x) {
	return min(x.x, min(x.y, x.z));
}

inline bool cmp(const node &x, const node &y) {
	return (fst1(x) == fst1(y)) ? ((snd1(x) == snd1(y)) ? ird1(x) > ird1(y) : snd1(x) > snd1(y)) : fst1(x) > fst1(y);
}

inline bool cmp2(const node &x, const node &y) {
	return fst1(x) - snd1(x) < fst1(y) - snd1(y);
}

inline bool cmp3(const node &x, const node &y) {
	return fst1(x) - snd1(x) > fst1(y) - snd1(y);
}

inline int fnd(const node &x, const int &num) {
	if (x.x == num) return 0;
	else if (x.y == num) return 1;
	return 2; 
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = read();
	while (t --) {
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < 4; ++i) {
			qu[i].clear();
		}
		ans = 0;
		n = read();
		for (int i = 0; i < n; ++i) {
			a[i].x = read(), a[i].y = read(), a[i].z = read();
		}
		sort(a, a + n, cmp);
		for (int i = 0; i < n; ++i) {
			if (cnt[fnd(a[i], fst1(a[i]))] < n / 2) {
				cnt[fnd(a[i], fst1(a[i]))] ++;
				ans += fst1(a[i]);
				qu[fnd(a[i], fst1(a[i]))].push_back(a[i]);
			} else {
				qu[3].push_back(a[i]);
			}
		}
		if (qu[3].empty()) {
			printf("%lld\n", ans);
			continue;
		}
		int maxn, now = 0;
		if (qu[0].size() == n / 2) maxn = 0;
		else if (qu[1].size() == n / 2) maxn = 1;
		else maxn = 2;
		sort(qu[maxn].begin(), qu[maxn].end(), cmp2);
		sort(qu[3].begin(), qu[3].end(), cmp3);
		while (now < min(qu[maxn].size(), qu[3].size()) && fst1(qu[maxn][now]) + snd1(qu[3][now]) < snd1(qu[maxn][now]) + fst1(qu[3][now])) {
			ans = ans - fst1(qu[maxn][now]) + snd1(qu[maxn][now]) + fst1(qu[3][now]);
			cnt[fnd(qu[maxn][now], snd1(qu[maxn][now]))] ++;
			now ++;
		}
		for (int i = now; i < qu[3].size(); ++i) {
			ans += snd1(qu[3][i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

/*

1
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522


*/
