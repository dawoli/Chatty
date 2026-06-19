#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100001], box[100001], cnt, maxn;
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		box[a[i]]++;
		maxn = max(maxn, a[i]);
	}
	int left = box[0], death = 0;
	for (int i = 1; i <= maxn; i++) {
		int x = min(left, box[i]);
		left -= x;
		left += box[i];
		death += x;
	}
	cout << n - death << endl;
	return 0;
}

