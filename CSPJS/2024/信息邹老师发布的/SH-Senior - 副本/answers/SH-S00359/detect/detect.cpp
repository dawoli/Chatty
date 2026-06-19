#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int t;
int n, m, l, v;
struct car {
	int d, v, a;
} c[MAXN];

int p[MAXN];
bool flag[MAXN];		//判断超速 
int cnt;		//超速车辆数量 
struct s {
	int l, r;		//左右闭 
	bool flag;
} seg[MAXN];
bool operator< (s s1, s s2) {
	if (s1.l < s2.l) return true;
	else if (s1.l > s2.l) return false;
	else if (s1.r < s2.r) return true;
	else return false;
} 
//struct segTree {
//	int tr[MAXN * 4];
//	int lz[MAXN * 4];
//	void clear(int l, int r, int p) {
//		for (int i = 0; i < MAXN * 4; ++i) tr[i] = lz[i] = 0;
//	}
//	void pushDown(int l, int r, int p) {
//		if (lz[p]) {
//			int mid = ((l + r) >> 1);
//			tr[p * 2] += lz[p] * (mid - l + 1);
//			tr[p * 2 + 1] += lz[p] * (r - mid - 1 + 1);
//			lz[p * 2] += lz[p];
//			lz[p * 2 + 1] += lz[p];
//			lz[p] = 0;
//		}
//	}
//	void modify(int l, int r, int s, int t, int v, int p) {
//		if (s > r || t < l) return;
//		int mid = ((l + r) >> 1);
//		if (l >= s && r <= t) {
//			tr[p] += v * (r - l + 1);
//			lz[p] += v;
//			return;
//		}
//		pushDown(l, r, p);
//		modify(l, mid, s, t, v, p * 2), modify(mid + 1, r, s, t, v, p * 2 + 1);
//	}
//	int query(int l, int r, int s, int t, int p) {
//		if (s > r || t < l) return 0;
//		int mid = ((l + r) >> 1);
//		
//		if (l >= s && r <= t) {
//			return tr[p];
//		}
//		pushDown(l, r, p);
//		return query(l, mid, s, t, p * 2) + query(mid + 1, r, s, t, p * 2 + 1);
//	}
//} segtr, segflag;
int lowbit(int x) {
		return x & (-x);
	}
struct tr {
	int t[MAXN];
	void clear(int a, int b, int c) {
		for (int i = 0; i < MAXN; ++i) t[i] = 0;
	}
	
	void modify(int p, int v) {
		if (p == 0) return;
		for (int x = p; x <= m + 1; x += lowbit(x)) {
			t[x] += v;
		}
		//for (int i = 1; i <= m; ++i) cout << t[i] << endl;
	} 
	int query(int p) {
		int res = 0;
		for (int x = p; x > 0; x -= lowbit(x)) {
			res += t[x];
		}
		return res;
	}
	
	
}segtr, segflag;


int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	m = 10;
	
	cin >> t;
	while (t--) {
		scanf("%d%d%d%d", &n, &m, &l, &v);
		segtr.clear(1, m, 1);
		segflag.clear(1, m, 1);
		memset(c, 0, sizeof(c));
		memset(p, 0, sizeof(p));
		memset(flag, 0, sizeof(flag));
		cnt = 0;
		memset(seg, 0, sizeof(seg));
		for (int i = 1; i <= n; ++i) scanf("%d%d%d", &c[i].d, &c[i].v, &c[i].a);
		for (int i = 1; i <= m; ++i) scanf("%d", &p[i]);
		sort(p + 1, p + m + 1);
		for (int i = 1; i <= n; ++i) {
			if (c[i].a == 0 && c[i].v > v) {
				if (c[i].d <= p[m]) {		//有摄像头观察到 
					//flag[i] = 1;//超速
					int monitor = lower_bound(p + 1, p + m + 1, c[i].d) - p;
					seg[++cnt] = {monitor, m, 0};
					//printf("=speed%d\n", i);
				}
			}
			if (c[i].a < 0) {
				if (c[i].v < v) continue;
				int monitor = lower_bound(p + 1, p + m + 1, c[i].d) - p;
				if (monitor == m + 1) {
					continue;
				}
				double tim = (c[i].v * 1.0l - v) / (-1 *c[i].a);
				double dis = c[i].v * tim + 0.5l * c[i].a * tim * tim + c[i].d;		//不再超速的地方
				if (p[monitor] - dis > 1e-8l) continue;
				int di = round(dis);
				if (abs(dis - di) > 1e-8l) di = ceil(dis);
				int stop = lower_bound(p + monitor, p + m + 1, di) - p - 1;
				
				seg[++cnt] = {monitor, stop, 0};
				//printf("%d, dis=%lf\n", i, dis);
				
			}
			if (c[i].a > 0) {
				if (c[i].d > p[m]) continue;
				if (c[i].v > v) {		//一冲入就超速 
					int monitor = lower_bound(p + 1, p + m + 1, c[i].d) - p;
					seg[++cnt] = {monitor, m, 0};
					//printf("seg=[%d,%d],+speed%d\n",seg[cnt].l, seg[cnt].r, i);
				} else {
					double dis = c[i].d + (v * v - c[i].v * c[i].v) / (2.0l * c[i].a);
					//cout << dis << endl;
					int di = round(dis);
					if (abs(dis - di) > 1e-8l) di = floor(dis);
					int start = upper_bound(p + 1, p + m + 1, di) - p;
					if (start == m + 1) continue;
					seg[++cnt] = {start, m, 0};
					//printf("seg=[%d,%d],+speed%d\n",seg[cnt].l, seg[cnt].r, i);
				}
			}
		}
		printf("%d ", cnt);
		sort(seg + 1, seg + cnt + 1);
		
		for (int i = 1; i <= cnt; ++i) {
			segtr.modify(seg[i].l, 1), segtr.modify(seg[i].l - 1, -1), segtr.modify(seg[i].r + 1, -1), segtr.modify(seg[i].r, 1);
		}
//		for (int i = 1; i <= m; ++i) printf("%d ", segtr.query( i, i));
		int ans = m;
		for (int i = 1; i <= cnt; ++i) {
			int que = segflag.query(seg[i].r) - segflag.query(seg[i].l - 1);
			
			if (que == 0) {
				//cout <<i<< "!!"<< que << endl;
				//寻找最大的 
				//cout << i << "!!" << segflag.query(1, m, seg[i].l, seg[i].r, 1) <<endl;
				int p = seg[i].l;
				int val = segtr.query(p);
				for (int j = seg[i].l + 1; j <= seg[i].r; ++j) {
					int tmp = segtr.query(j);
					if (tmp > val) {
						val = tmp;
						p = j;
					}
				}
				//printf("i=%d,que=%d,p=%d\n", i, que, p);
				//cout << p << endl;
				--ans;
				segflag.modify(p, 1);		//单点修区间查 
//				for (int i = 1; i <= m; ++i) {
//					printf("t[x]=%d, fl=%d\n", segflag.t[i], segflag.query(i) - segflag.query(i - 1));
//				} 
			}
			segtr.modify(seg[i].l, -1), segtr.modify(seg[i].l - 1, 1), segtr.modify(seg[i].r + 1, 1), segtr.modify(seg[i].r, -1);
			//cout << segflag.query(1, m, seg[i].l, seg[i].r, 1) << endl;
		}
		cout << ans << endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
