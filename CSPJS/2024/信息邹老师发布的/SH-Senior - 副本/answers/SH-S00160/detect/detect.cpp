#include <bits/stdc++.h>
using namespace std;

int num = 0xAC;
char ch = 0xAC;
int read() {
	bool neg = false;
	for (ch = getchar(); ch != '-' && (ch < '0' || ch > '9'); ch = getchar());
	if (ch == '-') {
		neg = true;
		ch = getchar();
	}
	for (num = 0; ch >= '0' && ch <= '9'; ch = getchar()) {
		num = (num << 3) + (num << 1) + (ch & 0xf);
	}
	return neg ? -num : num;
}

long long sq(long long x) {
	return x * x;
}
int ceildiv(long long p, long long q) {
	return (p-1ll) / q + 1ll;
}

const int N = 100004, M = 100004;

int n, m, L, V;
long long V2;

struct Car {
	int d, v, a;
	int xl, xr /*exclusive*/;
	int pl, pr /*exclusive*/;
	bool detectable;
	
	void calc_range() {
		if (!a) {
			xr = L+1;
			xl = (v > V) ? d : xr;
		}
		else if (a < 0) {
			if (v <= V)
				xl = xr = L+1;
			else {
				xl = d;
				xr = xl + ceildiv(sq(v) - V2, (-a) << 1);
			}
		}
		else {
			xr = L + 1;
			xl = d;
			if (v <= V)
				xl += (V2 - sq(v)) / (a << 1) + 1;
		}
	}
} c[N];

bool cmp(Car a, Car b) {
	return a.pr < b.pr;
}

set<pair<int, int> > detector;
int next_detector(int x) { // lower bound
	set<pair<int, int> >::iterator it = detector.lower_bound(make_pair(x, -1));
	return (it == detector.end()) ? m : it->second;
}

int cnt_preserved() {
	int cnt = 0;
	int nearest = -1;
	sort(c, c+n, cmp);
	for (int i = 0; i < n; i++) {
		if (!c[i].detectable || nearest >= c[i].pl)
			continue;
		cnt++;
		nearest = c[i].pr - 1;
//		printf("%d\n", nearest);
	}
	return cnt;
}

void solve() {
	int cnt_detectable = 0;
	detector.clear();
	n = read(); m = read(); L = read(); V = read();
	V2 = sq(V);
	for (int i = 0; i < n; i++) {
		c[i].d = read();
		c[i].v = read();
		c[i].a = read();
		c[i].calc_range(); 
	}
	for (int j = 0; j < m; j++) {
		detector.insert(make_pair(read(), j));
	}
	for (int i = 0; i < n; i++) {
		c[i].pl = next_detector(c[i].xl);
		c[i].pr = next_detector(c[i].xr);
		
		if (c[i].detectable = (c[i].pl < c[i].pr))
			cnt_detectable++;
		
//		printf("[%d, %d)\n", c[i].pl, c[i].pr);
	}
	printf("%d %d\n", cnt_detectable, m - cnt_preserved());
}

int main() {
	int T;
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	T = read();
	while (T--)
		solve();

	fclose(stdin);
	fclose(stdout);
	return 0;
}

