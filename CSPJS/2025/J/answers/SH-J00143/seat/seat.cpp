#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m, score[105], x = 0, a = 1;
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++) {
		cin >> score[i];
	}
	x = score[1];
	sort(score + 1, score + n * m + 1);
	for (int i = m * n;i >= 1;i--) {
		if (score[i] == x) {
			break;
		}
		a++;
	}
	int c, r;
	c = (a - 1) / m + 1;
	if (c % 2 == 1) {
		r = a % m;
		if (r == 0) r = m;
	} else {
		r = m - a % m + 1;
		if (r > m) r = 1;
	}
	cout << c  << " " << r << endl;
	return 0;
}
