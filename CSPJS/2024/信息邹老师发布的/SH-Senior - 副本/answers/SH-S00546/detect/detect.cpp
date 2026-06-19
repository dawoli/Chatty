#include <bits/stdc++.h>

std::fstream fin("detect.in");
std::fstream fout("detect.out");

int n, m;
long long L, V;
const int maxn = 100010;
long long d[maxn], v[maxn], a[maxn];
long long p[maxn];

struct stri {
	int l, r;
} lr[maxn];

long long dl[maxn], dr[maxn], jump[maxn];
bool used[maxn];
std::set<long long> pt;
//std::set<stri> gt;


long long left, right;
bool toofast(int i) {
	if (a[i] == 0) {
		left = d[i];
		right = L;
		return v[i] > V;
	} else if (a[i] > 0) {
		left = d[i] + std::ceil((long double)(V * V - v[i] * v[i]) / 2.0 / a[i]);
		right = L;
		return left <= right;
	} else {
		if (v[i] <= V) return false;
		left = d[i];
		right = std::min(d[i] + (long long) std::floor((long double)(v[i] * v[i] - V*V) / 2.0 / a[i]), L);
		return true;
	}
}

int dp(long long i, int depth) {
	used[i] = true;
	stri fake;
	fake.l = d[i], fake.r = 0;
	stri nxt = *upper_bound(lr, lr + n, fake);
	
	int tmp = dp(nxt, depth + 1);
	used[i] = false;
	return tmp;
}

bool operator<(stri l, stri r) {
	return l.l < r.l;
}
bool cmp(stri l, stri r) {
	return l.l < r.l;
}
void solve() {
	fin >> n >> m >> L >> V;
	for (int i = 1; i <= n; ++i) {
		fin >> d[i] >> v[i] >> a[i];
	}

	for (int i = 1; i <= m; ++i) {
		fin >> p[i];
		pt.insert(p[i]);
	}
	int ct = 0;
	for (int i = 1; i <= n; ++i) {
		if (toofast(i) and pt.upper_bound(left) != pt.lower_bound(right)){
			ct++;
			lr[ct].l = left;
			lr[ct].r = right;
		}
	}
	fout << ct << ' ';
	std::cout << ct;
	
	std::sort(lr, lr+ct, cmp);
	
	long long mm = 0;
	for (int i = 1; lr[i].l < 2 and i <= ct; i++){
		mm = std::max(maxi, lr[i].r);
	} jump[0] = mm;
	for (int i = 2; i <= ct; i++) {
		if (mm < jump[i]) 
		jump[i] = jump[i-1]
	}
	
	dp(0, 0);
	
}

int main() {
	int T;
	fin >> T;
	while(T --> 0) solve();
//	std::set<int> test;
//	test.insert(1);
//	test.insert(9);
//	test.insert(5);
//	test.insert(3);
//	
//	std::cout << *(test.lower_bound(7)) << *(test.upper_bound(8));
	return 0;
}
