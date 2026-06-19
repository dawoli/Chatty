#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 105;
struct Stu {
	int score;
	bool query;
	Stu() {
		score = 0;
	}
	bool operator<(Stu _cmp) const {
		return score>_cmp.score;
	}
}a[MAXN];
int n,m;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	a[1].query = true;
	for(int i = 1;i <= n*m;i ++) {
		cin >> a[i].score;
	}
	sort(a+1,a+n*m+1);
	int pos = -1;
	for(int i = 1;i <= n*m;i ++) {
		if(a[i].query) pos = i;
	}
//	cout << pos << '\n';
	int c = ceil((double)pos/n), r;
	if(c%2) r = pos - (c-1)*n;
	else r = (n + 1) - (pos - (c-1)*n);
	cout << c << " " << r;
	return 0;
}
