#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10, L = 1e6 + 10, INF = 0x3f3f3f3f;
int t, n, m, l, maxv, p[N], det[L], f[N];
bool spj[] = {true, true, true};
struct Car {
	int d, v, a;
} a[N];
struct Interval {
	int le, ri;
	bool operator<(const Interval &other) const {
		return ri == other.ri ? le < other.le : ri < other.ri;
	}
};
vector<Interval> vis;
bool cover[N];
inline double getPos(int d, double v, double a) {
	double ret = maxv * maxv - v * v;
	ret = ret / a / 2;
	return ret + d;
}
inline void add(int l, int r) {
	l = lower_bound(p + 1, p + m + 1, l) - p;
	r = upper_bound(p + 1, p + m + 1, r) - p - 1;
    vis.push_back({l, r});
}
bool check(int x) {
	for (int i = 0; i <= (1 << m) - 1; i++) {
		if (__builtin_popcount(i) != x)
		    continue;
	    memset(cover, false, sizeof(cover));
		for (int j = 1; j <= m; j++)
		    if (i & (1 << (j - 1))) {
		    	for (int k = 0; k < vis.size(); k++)
		    	    if (vis[k].le <= j && j <= vis[k].ri)
		    	        cover[k] = true;
			}
		bool ok = 1;
		for (int j = 0; j < vis.size(); j++)
		    if (!cover[j]) {
		        ok = 0;
		        break;
		    }
		if (ok)
		    return true;
	}
    return false;
}
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
    	vis.clear();
    	memset(det, 0, sizeof(det));
    	scanf("%d%d%d%d", &n, &m, &l, &maxv);
    	l++;
    	for (int i = 1; i <= n; i++) {
    	    scanf("%d%d%d", &a[i].d, &a[i].v, &a[i].a);
    	    a[i].d++;
    	    if (a[i].a != 0)
    	        spj[0] = false;
    	    if (a[i].a <= 0)
    	        spj[1] = false;
    	    if (a[i].a >= 0)
    	        spj[2] = false;
    	}
    	for (int i = 1; i <= m; i++) {
    	    scanf("%d", &p[i]);
    	    p[i]++;
    	    det[p[i]]++;
    	}
    	sort(p + 1, p + m + 1);
    	for (int i = 1; i <= l; i++)
    	    det[i] += det[i - 1];
    	for (int i = 1; i <= n; i++) {
    		if (a[i].a > 0) {
    			if (a[i].v > maxv) {
    				if (det[l] - det[a[i].d - 1] > 0)
    				    add(a[i].d, l);
    				continue;
				}
				double y = getPos(a[i].d, a[i].v, a[i].a);
				int x = (y == ceil(y) ? y + 1 : ceil(y));
    			if (x <= l && det[l] - det[x - 1] > 0)
    			    add(x, l);
			} else if (a[i].a < 0) {
				if (a[i].v <= maxv)
				    continue;
				double y = getPos(a[i].d, a[i].v, a[i].a);
				int x = (y == floor(y) ? y - 1 : floor(y));
				if (det[min(l, x)] - det[a[i].d - 1] > 0)
				    add(a[i].d, min(l, x));
			} else
				if (a[i].v > maxv && det[l] - det[a[i].d - 1] > 0)
				    add(a[i].d, l);
		}
		printf("%d ", (int)vis.size());
		if (spj[0] || spj[1] || !vis.size()) {
			printf("%d\n", vis.size() > 0 ? m - 1 : m);
			continue;
		}
		int l = 0, r = m, mid, ans = INF;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (check(mid)) {
				r = mid - 1;
				ans = mid;
			} else
			    l = mid + 1;
		}
		printf("%d\n", m - ans);
	}
	return 0;
}
