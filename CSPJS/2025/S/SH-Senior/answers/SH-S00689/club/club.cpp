// club

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

const int N = 2e5 + 10;
int gA[N][3], gC[N], gD[N];
PII gB[N][3];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		
		for (int i = 1; i <= n; i++) {
			cin >> gA[i][0] >> gA[i][1] >> gA[i][2];
			gB[i][0] = make_pair(gA[i][0], 0);
			gB[i][1] = make_pair(gA[i][1], 1);
			gB[i][2] = make_pair(gA[i][2], 2);
			sort(gB[i], gB[i] + 3); reverse(gB[i], gB[i] + 3);
			gC[i] = gB[i][0].first - gB[i][1].first;
		}
		
		int ans = 0, num[3] = {0};
		for (int i = 1; i <= n; i++) {
			num[gB[i][0].second]++;
			ans += gB[i][0].first;
		}
		
		for (int id = 0; id <= 2; id++)
			if (num[id] > n / 2) {
				int cur = 0;
				for (int i = 1; i <= n; i++)
					if (gB[i][0].second == id) gD[++cur] = gC[i];
				
				sort(gD + 1, gD + cur + 1);
				
				for (int i = 1; i <= num[id] - n / 2; i++) ans -= gD[i];
				break;
			}
		
		cout << ans << endl;
		memset(gA, 0, sizeof(gA));
		memset(gB, 0, sizeof(gB));
		memset(gC, 0, sizeof(gC));
		memset(gD, 0, sizeof(gD));
	}
	
	return 0;
} 
