#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring> 
using namespace std;
using i64 = long long;
const int MAXN = 2e5 + 5;
ifstream fin("color.in");
ofstream fout("color.out");
int a[MAXN], c[MAXN], last[5];

int main() {
	int T;
	fin >> T;
	while (T--) {
		int n;
		fin >> n;
		for (int i = 0; i < n; ++i) fin >> a[i];
		i64 ans = 0;
		if (n <= 15) {
			for (int i = 0; i < 1 << n; ++i) {
				memset(c, 0, sizeof(c));
				i64 sum = 0;
				for (int j = 0; j <= 2; ++j) last[j] = -1;
				for (int j = 0; j < n; ++j) 
					if (!(i & (1 << j))) {
						if ((last[j] != -1) && (a[last[0]] == a[j])) c[j] = a[j];
						last[0] = j;
					} else {
						if (a[last[1]] == a[j]) c[j] = a[j];
						last[1] = j;
					}
				for (int j = 0; j < n; ++j) sum += c[j];
				ans = max(ans, sum);
			}
			fout << ans << "\n";
		}
		else fout << 0 << "\n";
	}
	return 0;
} 
