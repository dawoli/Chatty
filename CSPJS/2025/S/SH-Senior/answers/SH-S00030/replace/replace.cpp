// AC自动机？？ 

#include <bits/stdc++.h>
using namespace std;

#define int long long

#define N 200005
#define L 5000005
#define S 30

int n, q;
string s1[N];
string s2[N];
string t1, t2;

// ----- 字符串哈希
#define MOD1 998244353
#define MOD2 1000000007
#define BASE 29

int qpow(int a, int p, int mod) {
	int res = 1;
	while (p) {
		if (p & 1) {
			res *= a;
			res %= mod;
		}
		p >>= 1;
		a = (a * a) % mod;
	}
	return res;
}

// 需要哈希的字符串：s2, t2 
int hsh_s2_1[N];
int hsh_s2_2[N];
int hsh_t2_1[L];
int hsh_t2_2[L];

void prep_hash_s2() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < s2[i].length(); j++) {
			hsh_s2_1[i] = ((hsh_s2_1[i] * BASE) % MOD1 + s2[i][j] - 'a') % MOD1;
			hsh_s2_2[i] = ((hsh_s2_2[i] * BASE) % MOD2 + s2[i][j] - 'a') % MOD2;
		}
	}
}

void prep_hash_t2() {
	for (int i = 1; i <= t2.length(); i++) {
		hsh_t2_1[i] = ((hsh_t2_1[i - 1] * BASE) % MOD1 + t2[i - 1] - 'a') % MOD1;
		hsh_t2_2[i] = ((hsh_t2_2[i - 1] * BASE) % MOD2 + t2[i - 1] - 'a') % MOD2;
	}
}

int get_hash_t2_1(int l, int r) {
	// l + 1 ~ r + 1
	return (hsh_t2_1[r + 1] - hsh_t2_1[l] * qpow(BASE, r + 1 - l, MOD1) % MOD1 + MOD1) % MOD1;
}

int get_hash_t2_2(int l, int r) {
	// l + 1 ~ r + 1
	return (hsh_t2_2[r + 1] - hsh_t2_2[l] * qpow(BASE, r + 1 - l, MOD2) % MOD2 + MOD2) % MOD2;
}
// ----- 

// ----- AC自动机 
int to[L][S];
int f[L]; // 失配指针 
int last[L];
vector<int> strl[L];
int nv = 1;
queue<int> acq;

void insert(const string &s, int v) {
	int p = 1;
	for (char c : s) {
		c -= 'a';
		if (!to[p][c]) {
			to[p][c] = ++nv;
		}
		p = to[p][c];
	}
	strl[p].push_back(v);
}

void build() {
	acq.push(1);
	f[1] = 0;
	for (int c = 0; c < 26; c++) {
		to[0][c] = 1;
	}
	while (!acq.empty()) {
		int u = acq.front();
		acq.pop();
		for (int c = 0; c < 26; c++) {
			if (!to[u][c]) {
				to[u][c] = to[f[u]][c];
				continue;
			}
			int i;
			int v = to[u][c];
			for (i = f[u]; i && !to[i][c]; i = f[i]);
			f[v] = to[i][c];
			if (!strl[f[v]].empty()) {
				last[v] = f[v];
			} else {
				last[v] = last[f[v]];
			}
			acq.push(to[u][c]);
		}
	}
}
// -----

int ans;

int solve() {
	if (t1.length() != t2.length()) {
		return 0;
	}
	int m = t1.length();
	int l = -1, r = -1;
	for (int i = 0; i < m; i++) {
		if (t1[i] != t2[i]) {
			if (l == -1) {
				l = i;
			}
			r = i;
		}
	}
	// run on acam
	int p = 1;
	ans = 0;
	for (int i = 0; i < m; i++) {
		int c = t1[i] - 'a';
		p = to[p][c];
		if (!strl[p].empty() || last[p]) { // 匹配到 s1 
			if (i >= r) {
				for (int pi = p; pi; pi = last[pi]) {
					
					
					for (int v : strl[pi]) {
						int sl = i - s1[v].length() + 1;
						if (sl <= l) { // 覆盖了 [l, r] 段 
							if (hsh_s2_1[v] == get_hash_t2_1(sl, i) &&
								hsh_s2_2[v] == get_hash_t2_2(sl, i)) {
								ans++;
							}
						}
					}
					
					
				}
			}
		}
	}
	return ans;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		insert(s1[i], i);
	}
	prep_hash_s2();
	build();
	while (q--) {
		cin >> t1 >> t2;
		prep_hash_t2();
		cout << solve() << endl;
	}
}
