#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

const int N = 1e5 + 7;
const double err = 0.01;
int T;
int n, m, l, v;

struct Car {
	int d, v, a;
} c[N];

int p[N], rp[N];
bool ok[N];

struct Itv {
	double a, b;
	// [a, b]
} itv[N];
int cnt;
vector<int> in[N];

bool cmp(Itv x, Itv y) {
	return x.a < y.a || (x.a == y.a and x.b < y.b);
}

bool gt(int x, int y) {
	return x > y;
}

int lb(int v) {
	int ans = lower_bound(rp, rp+m, v, gt) - rp;
	return m - ans;
}

void test() {
	cnt = 0;
	cin >> n >> m >> l >> v;
	for(int i=1; i<=n; i++) cin >> c[i].d >> c[i].v >> c[i].a;
	for(int i=1; i<=m; i++) cin >> p[i], rp[m-i] = p[i];
	bool ak = true;
	for(int i=1; i<=n; i++) {
		if(c[i].a != 0) ak = false; 
		if(c[i].a <= 0 and c[i].v <= v) continue; 
		if(c[i].v <= v and sqrt(c[i].v * c[i].v + 2.0 * c[i].a * (l - c[i].d)) <= v) continue; 
		if(c[i].a < 0) {
//			cout << i << " TYPE A" << endl;
			double t = (double)(v - c[i].v) / c[i].a;
			double s = c[i].d + c[i].v * t + 0.5 * c[i].a * t * t;
			int k1 = lower_bound(p+1, p+1+m, c[i].d) - p, k2 = lower_bound(p+1, p+1+m, min(s, (double)l)) - p;
			if(k1 != k2) cnt++, itv[cnt].a = c[i].d, itv[cnt].b = min(s - err, (double)l);
		} else if(c[i].a == 0) {
//			cout << i << " TYPE B" << endl;
			int k2 = lower_bound(p+1, p+1+m, c[i].d) - p;
			if(k2 != m+1) cnt++, itv[cnt].a = c[i].d, itv[cnt].b = l; 
		} else if(c[i].a > 0) {
//			cout << i << " TYPE C" << endl;
			if(c[i].v >= v) {	
				int k1 = lower_bound(p+1, p+1+m, c[i].d) - p, k2 = lower_bound(p+1, p+1+m, l) - p;
				if(k1 != k2) cnt++, itv[cnt].a = c[i].d, itv[cnt].b = l;
			} else {
				double t = (double)(v - c[i].v) / c[i].a;
				double s = c[i].d + c[i].v * t + 0.5 * c[i].a * t * t;
				int k1 = lower_bound(p+1, p+1+m, s) - p, k2 = lower_bound(p+1, p+1+m, l) - p;
				if(k1 != k2) cnt++, itv[cnt].a = s + err, itv[cnt].b = l;
			}
		}
	}
	cout << cnt << ' ';
	if(ak) {
		cout << m - 1 << endl;
		return;
	}
	sort(itv+1, itv+cnt+1, cmp);
	for(int i=1; i<=cnt; i++) {
		int t1 = lower_bound(p+1, p+1+m, itv[i].a) - p, t2 = lower_bound(p+1, p+1+m, itv[i].b) - p;
//		cout << i << ' ' << t1 << ' ' << t2 << endl;
//		if(p[t1] == itv[cnt].a) t1++;
		for(int z=t1; z<=t2; z++) in[z].push_back(i); 
	}  
	fill(ok+1, ok+cnt+1, 0);
	
//	for(int i=1; i<=cnt; i++) cout << itv[i].a << ' ' << itv[i].b << endl;
//	for(int i=1; i<=m; i++) for(int z=0; z<in[i].size(); z++) cout << in[i][z] << ' ';
	
	int ans = 0;
	for(int i=1; i<=cnt; i++) {
		if(ok[i]) continue;
		int k1 = lower_bound(p+1, p+1+m, itv[i].a) - p, k2 = lower_bound(p+1, p+1+m, itv[i].b) - p;
		int j = i;
		double ih = itv[i].b;
		while(k2 > k1) {
			j++;
			ih = min(ih, itv[j].b);
			while(p[k1] >= itv[i].a and p[k1] <= ih) k1++;
			while(p[k2] >= itv[i].a and p[k2] <= ih) k2--;
		}
		k1 = lower_bound(p+1, p+1+m, itv[j].a) - p;
		while(!(p[k1] >= itv[i].a and p[k1] <= ih)) j--, k1 = lower_bound(p+1, p+1+m, itv[j].a) - p;
		for(int z=0; z<in[k1].size(); z++) ok[in[k1][z]] = true;
		ans++; 
	}
	cout << m - ans << endl;
//	for(int i=1; i<=cnt; i++) cout << itv[i].a << ' ' << itv[i].b << endl;
}

signed main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	cin >> T;
	while(T--) test();
	return 0;
}

/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15

3 3
*/
 
