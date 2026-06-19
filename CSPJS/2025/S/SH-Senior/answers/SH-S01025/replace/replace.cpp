#include <bits/stdc++.h>
const long long mod1 = 1e9 + 7;
const long long mod2 = 998244353;
const long long base1 = 131;
const long long base2= 131223211;
const int maxn = 2e5 + 10;
struct st {
	std::string s1, s2;
	long long h1, h2;
} s[maxn];
long long hashs1[maxn], hashs2[maxn];
std::map<std::pair<long long, long long> , long long> cnt;
long long ksm(long long x, int k, long long p) {
	long long res = 1;
	while (k) {
		if (k & 1)
			res = res * x % p;
		x = x * x % p;
		k >>= 1;
	}
	return res;
}
long long hash1(std::string o) {
	long long h = 0;
	for (int i = 0; i < o.size(); i++) {
		h = (h * base1 % mod1 + o[i] - 'a' + 1) % mod1;
	}
	return h;
}
long long hash2(std::string o) {
	long long h = 0;
	for (int i = 0; i < o.size(); i++) {
		h = (h * base2 % mod2 + o[i] - 'a' + 1) % mod2;
	}
	return h;
}
void hash_string1(std::string o) {
	hashs1[0] = 0;
	for (int i = 0; i < o.size(); i++) {
		if (i != 0)
			hashs1[i] = (hashs1[i - 1] * base1 % mod1 + o[i] - 'a' + 1) % mod1;
		else
			hashs1[i] = o[i] - 'a' + 1;
	}
}
void hash_string2(std::string o) {
	hashs2[0] = 0;
	for (int i = 0; i < o.size(); i++) {
		if (i != 0)
			hashs2[i] = (hashs2[i - 1] * base2 % mod2 + o[i] - 'a' + 1) % mod2;
		else
			hashs2[i] = o[i] - 'a' + 1;
	}
}
long long h(int l, int r) {
	return (hashs1[r] - hashs1[l - 1] * ksm(base1, r - l + 1, mod1) % mod1 + mod1) % mod1;
}
long long h2(int l, int r) {
	return (hashs2[r] - hashs2[l - 1] * ksm(base2, r - l + 1, mod2) % mod2 + mod2) % mod2;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int ans = 0;
	int n, q;
	std::cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		std::cin >> s[i].s1 >> s[i].s2;		
		s[i].h1 = hash1(s[i].s1);
		s[i].h2 = hash2(s[i].s2);
		cnt[{s[i].h1, s[i].h2}]++;
	}
	std::string s1, s2;
	int difl, difr;
	for (int i = 1; i <= q; i++) {
		ans = 0;
		std::cin >> s1 >> s2;	
		if (s1.size() != s2.size()) {
			printf("0\n");
			continue;
		}
		int difl = s1.size(), difr = -1;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i]) {
				difl = std::min(difl, i);
				difr = i;
			}
		}
		hash_string1(s1);
		hash_string2(s2);
		for (int l = 0; l < s1.size(); l++) {
			for (int len = 1; l + len - 1 < s1.size(); len++) {//len = s1.size() - l; len >= 1; len--
			//int len = 1; l + len - 1 < s1.size(); len++
				int r = l + len - 1;
				if (!(l <= difl && difr <= r)) //不是全部包含肯定不可以 
					continue;//break;
				if (h(l, r) == h2(l, r))
					continue;
				long long two = h2(l, r), one = h(l, r);
				if (cnt.count({one, two})){
					ans += cnt[{one, two}];
				}
			}
		}
		printf("%d\n", ans);
	}
}
