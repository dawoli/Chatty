#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n, a[5005], ans = 0;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	int x = 0, m = 0;
	if (n >= 3) {
		for (int i = 0;i < 3;i++) {
			x += a[i];
			if (m < a[i]) m = a[i];
		}
	}
	if (x > 2 * m) ans++;
	cout << ans << endl;
	return 0;
}
