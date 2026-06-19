#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 5;
ifstream fin("duel.in");
ofstream fout("duel.out");
int r[MAXN], cnt;

int main() {
	int n;
	fin >> n;
	for (int i = 1; i <= n; ++i) fin >> r[i];
	sort(r + 1, r + n + 1);
	int left = 1, first = 1;
	for (int i = 2; i <= n; ++i)
		if (r[i] > r[i - 1]) {
			++cnt;
			first = i;
		} else if ((r[i] == r[i - 1]) && (left - i + first)) ++cnt;
		else ++left;
	fout << n - cnt << "\n";
	return 0;
}
