#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t, n, a[N], res, cnt;
bool col[N], flag;
int cal(int b) {
	int ans = 1;
	for (int i = 1; i <= n; i ++) ans *= 2;
	return ans;
}
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	while (t --) {
		res = 0;
		cin >> n;
		for (int i = 1; i <= n; i ++) cin >> a[i];
		for (int i = 1; i <= cal(n); i ++) {
			flag = 1;
			cnt = 0;
			for (int j = 1; j <= n; j ++) {
				col[j] = (i >> (n - j)) & 1;
			}
			for (int j = 1; j < n; j ++) {
				flag = 1;
				int k = j + 1;
				while (flag && k <= n) {
					if (col[j] == col[k]) {
						if (a[j] == a[k]) cnt += a[k];
						flag = 0;
					}
					k ++;
				}
			}
			res = max(res, cnt);
		}
		cout << res << endl;
	}



	return 0;
}

