#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 5;
ifstream fin("detect.in");
ofstream fout("detect.out");
int d[MAXN], v[MAXN], a[MAXN], p[MAXN];
int main() {
	int T;
	fin >> T;
	while (T--) {
		int n, m, L, V;
		fin >> n >> m >> L >> V;
		bool flaga = true;
		for (int i = 1; i <= n; ++i) {
			fin >> d[i] >> v[i] >> a[i];
			if (a[i]) flaga = false;
		}
		for (int i = 1; i <= m; ++i) fin >> p[i];
		if (flaga) {
			int ans = 0;
			for (int i = 1; i <= n; ++i) {
				if (v[i] > V && d[i] <= p[m]) ++ans;
			}
			sort(d + 1, d + n + 1);
			if ((d[1] > p[m]) || (!ans)) fout << ans << " " << m << "\n";
			else fout << ans << " " << m - 1 << "\n";
			continue;
		} 
		fout << n << " " << m << "\n";
	} 
	return 0;
} 
