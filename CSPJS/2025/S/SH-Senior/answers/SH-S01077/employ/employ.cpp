#include<bits/stdc++.h>
#include<fstream>
std::ifstream fin("employ.in");
std::ofstream fout("employ.out");

int c[505];
const long long mod = 998244353;
int a[505];

int main(){
	int n, m; fin >> n >> m;
	std::string s; fin >> s;
	for (int i = 1; i <= n; ++i) {
		fin >> c[i]; a[i] = i;
	}
	int ans = 0;
	int cnt = 0; 
	for (int i = 1; i <= n; ++i) {
		if (a[i] <= cnt) {
			cnt++; continue;
		}
		if (s[i-1] =='0') {
			cnt++; continue;
		}
	}
	if (n - cnt >= m) ans++;
	while (std::next_permutation(a+1, a+n+1)) {
		cnt = 0; 
		for (int i = 1; i <= n; ++i) {
			if (c[a[i]] <= cnt) {
				cnt++; continue;
			}
			if (s[i-1] =='0') {
				cnt++; continue;
			}
		}
		if (n - cnt >= m) ans++;
	}
	fout << ans % mod;
}
