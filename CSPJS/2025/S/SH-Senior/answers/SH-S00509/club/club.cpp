#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct node {
	int x, id;
};
int t, sum, num[5];
int ch[5][5][maxn];
node a[maxn][5];
node maxx[maxn], mid[maxn];
bool vis[maxn];
bool cmp(node c, node d) {
	return c.x > d.x;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		memset(num, 0, sizeof(num));
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j].x;
				a[i][j].id = j; 
			}
			sort(a[i] + 1, a[i] + 4, cmp);
		}
		//cout << endl;
		sum = 0;
		int cnt[5][5];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			maxx[i] = a[i][1];
			mid[i] = a[i][2];
			ch[maxx[i].id][mid[i].id][++cnt[maxx[i].id][mid[i].id]] = maxx[i].x  - mid[i].x;
			sum += maxx[i].x;
			num[maxx[i].id]++;	 
			//cout << maxx[i].id << endl;
		}
		//cout << endl;
		//cout << sum << endl;
		for (int i = 1; i <= 3; i++) {
			//cout << num[i] << endl; 
			for (int j = 1; j <= 3; j++) {
				if (i != j) {
					sort(ch[i][j] + 1, ch[i][j] + 4);
				}
			} 
		}
		/*cout << endl;
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				for (int k = 1; k <= cnt[i][j]; k++) {
					cout << i << " " << j << " " << ch[i][j][k] << " " << endl;
				}
			} 
		}
		cout << endl;
		cout << n / 2 << endl;
		cout << endl;*/
		for (int i = 1; i <= 3; i++) {
			if (num[i] > n / 2) {
				//cout << i  << " " << num[i] << endl;
				for (int j = 1; j <= num[i] - n / 2; j++) {
					for (int k = 1; k <= 3; k++) {
						if (i != k) {
							if (ch[i][k][j] <= ch[i][6 - i - k][j] && num[k] + 1 <= n / 2) {
								sum -= ch[i][k][j];
								//cout << i << " " << k << " " << j << " " << ch[i][k][j] << endl;
								num[k]++;
							} else {
								sum -= ch[i][6 - i - k][j];
								//cout << i << " " << k << " " << j << " " << ch[i][k][j] << endl;
								num[6 - i - k]++;
							}
						}
					}
				}
			}
		}
		//cout << endl;
		cout << sum << endl;
	}
	return 0;
} 
