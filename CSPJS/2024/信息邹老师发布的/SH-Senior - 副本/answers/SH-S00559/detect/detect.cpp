# include <iostream>
using namespace std;
struct Node {
	int d, v, p;
}a[100001];
int main() {
	int t;
	cin >> t;
	int n, m, s, l, b[100001], num, ans = 0;
	for (int i = 0; i < t; i++) {
		cin >> n >> m >> s >> l;
		for (int j = 0; j < n; j++) {
			cin >> a[j].d >> a[j].v >> a[j].p;
		}
		for (int j = 0; j < n; j++) {
			cin >> b[j];
		}
		for (int j = 0; j < n; j++) {
			if (a[j].p == 0) {
				if (a[j].v > l && a[j].d <= b[m - 1]) {
					ans++;
				}
			} else {
				if (a[j].v > l) {
					if (a[j].d <= b[m - 1]) {
						ans++;
					}
				} else {
					num = (l * l - a[j].v * a[j].v) / (2 * a[j].p);
					if (a[j].d + num <= b[m - 1]) {
						ans++;
					}
				}
			}
		}
		cout << ans << " " << m - 1 << endl;
	}
	return 0;
}
