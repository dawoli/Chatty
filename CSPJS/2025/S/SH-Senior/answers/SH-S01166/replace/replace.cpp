#include <cstring>
#include <iostream>
#include <vector>

const int base = 131;

struct hash {
	unsigned long long val;

	hash() {}

	hash(std::string s) {
		val = 0;
		for (int i = 0; i < s.size(); i++)
			val = val * base + s[i] - 'a' + 1;
	}

	hash(unsigned long long val) {
		this -> val = val;
	}

	unsigned long long quickPow(int x) {
		unsigned long long res = 1, a = base;
		for (; x; x >>= 1) {
			if (x & 1) res = res * a;
			a = a * a;
		}
		return res;
	}

	hash operator+ (const hash x) {
		return hash(val + x.val);
	}

	hash operator- (const hash x) {
		return hash(val - x.val);
	}

	bool operator== (const hash x) {
		return this -> val == x.val;
	}

	hash operator<< (const int x) {
		return hash(val * quickPow(x));
	}
}s1[1005], s2[1005];

int n, q;
std::string ss[1005];
std::vector <int> next[1005];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::cin>>n>>q;
	for (int i = 1; i <= n; i++) {
		std::string tmp, s = " "; std::cin>>tmp;
		s1[i] = hash(tmp); s.append(tmp); ss[i] = s;
		next[i].push_back(0), next[i].push_back(0);
		for (int k = 2, j = 0; k < s.size(); k++) {
			while (j && s[j + 1] != s[k]) j = next[i][j];
			if (s[j + 1] == s[k]) j++;
			next[i].push_back(j);
		}

		std::cin>>tmp; s = " "; s.append(tmp); s2[i] = hash(tmp);
	}

	for (int t = 1; t <= q; t++) {
		std::string tmp, t1 = " ", t2 = " ";
		std::cin>>tmp; hash t1h(tmp); t1.append(tmp);
		std::cin>>tmp; hash t2h(tmp); t2.append(tmp);

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int k = 1, j = 0; k < t1.size(); k++) {
				while (j && ss[i][j + 1] != t1[k]) j = next[i][j];
				if (ss[i][j + 1] == t1[k]) j++;
				if (j == next[i].size() - 1) {
					int d = t1.size() - k - 1;
					if (t1h - (s1[i] << d) + (s2[i] << d) == t2h) ans++;
				}
			}
		}
		std::cout<<ans<<"\n";
	}
}