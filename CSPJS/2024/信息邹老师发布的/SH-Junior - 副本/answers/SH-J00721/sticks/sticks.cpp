#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 1e5 + 15;
ifstream fin("sticks.in");
ofstream fout("sticks.out");
int ans[MAXN] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200};
int main() {
	int T;
	fin >> T;
	for (int i = 18; i <= 100005; ++i) ans[i] = ans[i - 7] * 10 + 8;	
	while (T--) {
		int n;
		fin >> n;
		fout << ans[n] << "\n"; 
	}
	return 0;
}
