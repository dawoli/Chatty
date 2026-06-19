#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;

struct info {
	int first, second, third, cost1, cost2;
};
int n, t, ans;
int a[N][20];
int club[20][N], num[20], rk[N];
int ava[20];
info belong[N];
bool cmp(int a, int b) {
	if(belong[a].cost1 > belong[b].cost1) return 1;
	if(belong[a].cost1 == belong[b].cost1)
		if(belong[a].cost2 > belong[b].cost2)
			return 1;
	return 0;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	while(t --) {
		ans = 0;
		memset(num, 0, sizeof(num));
		memset(belong, 0, sizeof(belong));
		ava[1] = ava[2] = ava[3] = 1;
		
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) {
			scanf("%d %d %d", &a[i][1], &a[i][2], &a[i][3]);
			rk[i] = i;
		}
		
		for(int i = 1; i <= n; i ++) {
			int maxx = -1, id = 0;
			for(int j = 1; j <= 3; j ++) {
				if(maxx < a[i][j]) {
					maxx = a[i][j];
					id = j;
				}
			}
			belong[i].first = id;
			maxx = -1, id = 0;
			for(int j = 1; j <= 3; j ++) {
				if(maxx < a[i][j] && j != belong[i].first) {
					maxx = a[i][j];
					id = j;
				}
			}
			belong[i].second = id;
			for(int j = 1; j <= 3; j ++) {
				if(j != belong[i].first && j != belong[i].second)
					belong[i].third = j;
			}
			belong[i].cost1 = a[i][belong[i].first] - a[i][belong[i].second];
			belong[i].cost2 = a[i][belong[i].second] - a[i][belong[i].third];
		}
		
		sort(rk + 1, rk + 1 + n, cmp);
		for(int i = 1; i <= n; i ++) {
			int ths = rk[i];
			//cout << ths << ' ';
			int first = belong[ths].first, second = belong[ths].second, third = belong[ths].third;
			if(ava[first]) {
				club[first][++num[first]] = ths;
				if(num[first] >= n / 2) ava[first] = 0;
			}
			else if(ava[second]) {
				club[second][++num[second]] = ths;
				if(num[second] >= n / 2) ava[second] = 0;
			}
			else {
				club[third][++num[third]] = ths;
				if(num[third] >= n / 2) ava[third] = 0;
			}
		}
		//cout << '\n';
		
		for(int j = 1; j <= 3; j ++) {
			for(int i = 1; i <= num[j]; i ++) {
				ans += a[club[j][i]][j];
				//cout << club[j][i] << ' ';
			}
			//cout << '\n';
		}
		cout << ans << '\n';
	}
		
	return 0;
}
