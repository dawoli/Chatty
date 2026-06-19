#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define int long long
using namespace std;

int d[100005], v[100005], a[100005], p[100005], cnt[100005], lt[100005], rt[100005];
int read(){
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9'){if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9'){x = (x << 1) + (x << 3) + (c - '0'); c = getchar();}
	return x * f;
}
signed main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	cin >> t;
	while (t--){
		int n, m, L, V;
		cin >> n >> m >> L >> V;
		for (int i = 1; i <= n; i++)
			d[i] = read(), v[i] = read(), a[i] = read();
		for (int i = 1; i <= m; i++)
			p[i] = read();
		// first question
		int count = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] > 0){
				if (d[i] > p[m]) continue;
				int s = p[m] - d[i];
				count += (sqrt(v[i] * v[i] + 2 * a[i] * s) > V);
			} else {
				if (d[i] > p[m]) continue;
				int cur = lower_bound(p+1, p+m+1, d[i]) - p;
				int s = p[cur] - d[i];
				if (v[i] * v[i] + 2 * a[i] * s <= 0) continue;
				count += (sqrt(v[i] * v[i] + 2 * a[i] * s) > V);
			}
		cout << count << ' ';
		// second question
		if (n <= 3000 && m <= 3000){
			// O(n^2)
			memset(cnt, 0, sizeof(cnt));
			memset(lt, 0, sizeof(lt));
			memset(rt, 0, sizeof(rt));
			int summ = 0;
			for (int i = 1; i <= n; i++)
				if (a[i] > 0){
					int s = p[m] - d[i];
					if (d[i] > p[m] || sqrt(v[i] * v[i] + 2 * a[i] * s) <= V) continue;
					int l = lower_bound(p+1, p+m+1, d[i]) - p, r = m;
					while (l < r){
						int mid = (l + r) / 2;
						s = p[mid] - d[i];
						if (sqrt(v[i] * v[i] + 2 * a[i] * s) <= V)
							l = mid + 1;
						else
							r = mid;
					}
					lt[i] = l, rt[i] = m;
					for (int j = l; j <= m; j++)
						cnt[j]++;
					summ++;
				} else {
					int cur = lower_bound(p+1, p+m+1, d[i]) - p;
					int s = p[cur] - d[i];
					if (v[i] * v[i] + 2 * a[i] * s <= 0) continue;
					if (d[i] > p[m] || sqrt(v[i] * v[i] + 2 * a[i] * s) <= V) continue;
					int l = cur, r = m;
					while (l < r){
						int mid = (l + r + 1) / 2;
						s = p[mid] - d[i];
						if (v[i] * v[i] + 2 * a[i] * s <= 0 || sqrt(v[i] * v[i] + 2 * a[i] * s) <= V)
							r = mid - 1;
						else
							l = mid;
					}
					lt[i] = cur, rt[i] = l;
					s = p[l] - d[i];
					int ss = p[cur] - d[i];
					for (int j = cur; j <= l; j++)
						cnt[j]++;
					summ++;
				}
			int ans = 0;
			while (summ > 0){
				int maxi = 0;
				for (int i = 1; i <= m; i++)
					if (cnt[i] > cnt[maxi])
						maxi = i;
				ans++;
				int temp = cnt[maxi], ssc = 0;
				for (int i = 1; i <= n; i++){
					if (lt[i] == 0 && rt[i] == 0) continue;
					if (!(lt[i] <= maxi && maxi <= rt[i])) continue;
					for (int j = lt[i]; j <= rt[i]; j++)
						cnt[j]--;
					int s = p[maxi] - d[i];
					summ--;
					ssc++;
					lt[i] = 0, rt[i] = 0;
				}
				if (ssc != temp) return 0;
			}
			cout << m - ans << '\n';
		} else {
			cout << m - (count > 0) << '\n';
		}
	}
	return 0;
}
