#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXL = 2e5 + 5;
ifstream fin("chain.in");
ofstream fout("chain.out");
int l[MAXN], r[MAXN], c[MAXN]; 
bool appear[MAXL];
int main() {
	int T;
	fin >> T;
	while (T--) {
		int n, k, q;
		fin >> n >> k >> q;
		bool flag = false;
		for (int i = 1; i <= n; ++i) {
			int l;
			fin >> l;
			string s;
			fin >> s;
			for (int i = 0; i < l; ++i) appear[s[i] - '0'] = true;
		}
		for (int i = 1; i <= q; ++i) {
			int r, c;
			fin >> r >> c;
			if (!appear[c]) flag = true;
		} 
		if (flag) fout << 0 << "\n";
		else fout << 1 << "\n"; 
	}
	return 0;
} 
