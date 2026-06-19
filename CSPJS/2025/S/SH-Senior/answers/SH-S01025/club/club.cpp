#include<bits/stdc++.h>
const int maxn = 1e5 + 10;
long long a[maxn][4];
bool vis[maxn][4];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		long long sum = 0;
		std::priority_queue<std::pair<long long, int> > q1, q2, q3;
		int n, benchmark;
		scanf("%d", &n);
		benchmark = n / 2;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++) {
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				q1.push({-(a[i][1] - std::max(a[i][2], a[i][3])), i});
				sum += a[i][1];
			} else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
				q2.push({-(a[i][2] - std::max(a[i][1], a[i][3])), i});
				sum += a[i][2];
			} else {
				q3.push({-(a[i][3] - std::max(a[i][1], a[i][2])), i});
				sum += a[i][3];
			}
		}	
		while (q1.size() > benchmark) {
			sum += q1.top().first;
			q1.pop();
		}	
		while (q2.size() > benchmark) {
			sum += q2.top().first;
			q2.pop();
		}
		while (q3.size() > benchmark) {
			sum += q3.top().first;
			q3.pop();
		}
		printf("%lld\n", sum);
	}
} 
