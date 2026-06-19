#include <bits/stdc++.h>
using namespace std;
const int N = 1000009;
long long t, a[N][4], sum[4], flag[N][4], ans = 0, shuzu[N], x = 1;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) {
		ans = 0, x = 1;
		for (int i = 0; i < 4; i++) {
			sum[i] = 0;
		}
		for (int i = 0; i < 100009; i++) {
			flag[i][0] = 0;
			flag[i][1] = 0;
			flag[i][2] = 0;
			flag[i][3] = 0;
			shuzu[i] = 0;
			a[i][0] = 0;
			a[i][1] = 0;
			a[i][2] = 0;
			a[i][3] = 0;
		}
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				sum[1]++;
				flag[i][1] = 1;
				ans += a[i][1];
			} else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
				sum[2]++;
				flag[i][2] = 1;
				ans += a[i][2];
			} else {
				sum[3]++;
				flag[i][3] = 1;
				ans += a[i][3];
			}
		}
		if(sum[1] > n / 2) {
			int cha = sum[1] - n / 2;
			for (int i = 1; i <= n; i++) {
				if(flag[i][1] == 1) {
					shuzu[x++] = min(abs(a[i][1] - a[i][2]), abs(a[i][1] - a[i][3]));
				}
			}
			sort(shuzu + 1, shuzu + sum[1] + 1);
			for (int i = 1; i <= cha; i++) {
				ans -= shuzu[i];
			}
			cout << ans;
		} else if(sum[2] > n / 2) {
			int cha = sum[2] - n / 2;
			for (int i = 1; i <= n; i++) {
				if(flag[i][2] == 1) {
					shuzu[x++] = min(abs(a[i][2] - a[i][1]), abs(a[i][2] - a[i][3]));
				}
			}
			sort(shuzu + 1, shuzu + sum[2] + 1);
			for (int i = 1; i <= cha; i++) {
				ans -= shuzu[i];
			}
			cout << ans;
		} else if(sum[3] > n / 2) {
			int cha = sum[3] - n / 2;
			for (int i = 1; i <= n; i++) {
				if(flag[i][3] == 1) {
					shuzu[x++] = min(abs(a[i][3] - a[i][1]), abs(a[i][3] - a[i][2]));
				}
			}
			sort(shuzu + 1, shuzu + sum[3] + 1);
			for (int i = 1; i <= cha; i++) {
				ans -= shuzu[i];
			}
			cout << ans;
		} else {
			cout << ans;
		}
		if (t) {
			cout << endl;
		}
	} 
	return 0;
} 
