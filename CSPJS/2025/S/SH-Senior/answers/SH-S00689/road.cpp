// road

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

const int N = 1e6 + 10, M = 2e4 + 10, S = 20, INF = 1e18;
struct EDGE {
	int a, b, c;
	
	friend bool operator < (const EDGE &x, const EDGE &y) {
		return x.c < y.c;
	}
}gE[N], gCand[N], gA[N];
struct BOUNS {
	int cost;
	PII val[M];
}gB[S];
int gF[N], gId[N], gLen[N];

int Find(int x) {
	if (x == gF[x]) return x;
	return gF[x] = Find(gF[x]);
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	for (int i = 1; i <= m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		
		gE[i] = (EDGE){a, b, c};
	}
	
	sort(gE + 1, gE + m + 1);
	
	for (int i = 1; i <= k; i++) {
		cin >> gB[i].cost;
		for (int j = 1; j <= n; j++)
			cin >> gB[i].val[j].first, gB[i].val[j].second = j;
		
		sort(gB[i].val + 1, gB[i].val + n + 1);
	}
	
	int mxn = (1LL << k), cur = 0, ans = INF;
	for (int bit = 0; bit < mxn; bit++) {
		int sum = 0;
		
		for (int i = 1; i <= n + k; i++)
			gF[i] = i;
		
		int pop = 0;
		for (int i = 1; i <= k; i++) {
			gLen[i] = 1;
			if (bit & (1LL << i - 1)) {
				gId[++pop] = i;
				sum += gB[i].cost;
			}
		}
		
		int cur = 0, now = 1, test = 0;
		while (cur < n + pop - 1) {
			pair<EDGE, int> mn = make_pair(gE[now], 0);
			for (int i = 1; i <= pop; i++) {
				int id = gId[i], len = gLen[id];
				mn = min(mn, make_pair((EDGE){id + n, gB[id].val[len].second, gB[id].val[len].first}, id));
			}
			
			int a = mn.first.a, b = mn.first.b, c = mn.first.c, id = mn.second, fx = Find(a), fy = Find(b);
			if (fx != fy) gF[fx] = fy, sum += c, cur++;
			
			if (!id) now++;
			else gLen[id]++; 
		}
		
		ans = min(ans, sum);
	}
	
	cout << ans << endl;
	return 0;
}
