#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
using i64 = long long;
ifstream fin("club.in");
ofstream fout("club.out");
const int MAXN = 1e5 + 5;
int a[MAXN][5];
pair<int, int> tmp[MAXN][5];
struct person {
	int firstt, secondd, id;
	bool operator> (person rhs) const {
		if (firstt == rhs.firstt) return secondd > rhs.secondd;
		return firstt > rhs.firstt; 
	}
} persons[MAXN];
signed main() {
	int t;
	fin >> t;
	while (t--) {
		int n;
		fin >> n;
		for (int i = 1; i <= n; ++i) {
			fin >> a[i][1] >> a[i][2] >> a[i][3];
			for (int j = 1; j <= 3; ++j) tmp[i][j] = {a[i][j], j};
			sort(tmp[i] + 1, tmp[i] + 4);
			persons[i].firstt = tmp[i][3].first - tmp[i][2].first;
			persons[i].secondd = tmp[i][2].first - tmp[i][1].first;
			persons[i].id = i;
		}
		sort(persons + 1, persons + n + 1, greater<person>());
		int cnt[5] = {};
		i64 ans = 0;
		for (int j = 1; j <= n; ++j) {
			int i = persons[j].id;
			int club1 = tmp[i][3].second;
			int club2 = tmp[i][2].second;
			int club3 = tmp[i][1].second;
			//fout << i << " " << club1 << " " << club2 << " " << club3 << "\n"; 
			if (cnt[club1] < n / 2) {
				++cnt[club1];
				ans += tmp[i][3].first; 
			} else if (cnt[club2] < n / 2) {
				++cnt[club2];
				ans += tmp[i][2].first;
			} else if (cnt[club3] < n / 2) {
				++cnt[club3];
				ans += tmp[i][1].first;
			}
		}
		fout << ans << "\n";
		//fout << tmp[1][1].first << " " << tmp[1][1].second << "\n\n";
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
