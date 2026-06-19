#include <bits/stdc++.h>
using namespace std;
int a[100010][3];
int cnt[100010][3];
int main() {
	//  freopen("club.in", "r", stdin);
	//  freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[1][2];
		}
		int c = n / 2;
		for (int i = 1; i <= n; i++) {
			int id = max(a[i][0], max(a[i][1], a[i][2]));
			if (id == a[i][0]) {
				cnt[i][0] = a[i][0];
			} else if (id == a[i][1]) {
				cnt[i][1] = a[i][1];
			} else {
				cnt[i][2] = a[i][2];
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << cnt[i][0] << endl;
			cout << cnt[i][1] << endl;
			cout << cnt[i][2] << endl;
		}
	}
	
	return 0;
}
