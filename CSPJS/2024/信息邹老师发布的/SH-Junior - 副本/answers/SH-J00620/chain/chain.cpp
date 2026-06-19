// chain

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

const int N = 2e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
struct QUERY {
	int r, c;
}gQ[N];
vector<int> gVec[N];
vector<PII> gPos[N];
int n, k, q;

// BF1 5pts #1
namespace BF1 {
	int gAns[N];
	void Solve() {
		memset(gAns, 0x3f, sizeof(gAns));
		
		for (int i = 1; i <= n; i++) {
			int len = gVec[i].size(), ans = 0, mn = INF;
			for (int j = 0; j < len; j++) {
				int to = gVec[i][j]; 
				if (mn < INF / 2) gAns[to] = min(gAns[to], j + 1 - mn);
				if (to == 1) mn = j;
			}
		}
		
		for (int i = 1; i <= q; i++) 
			cout << (gAns[gQ[i].c] <= k) << endl;
	}
}

signed main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	
	while (t--) {
		cin >> n >> k >> q;
		
		for (int i = 1, len = 0; i <= n; i++) { cin >> len;
			for (int j = 1, x = 0; j <= len; j++) {
				cin >> x, gVec[i].push_back(x), gPos[x].push_back(make_pair(i, j));
			}
		}
		
		bool r1 = true;
		for (int i = 1; i <= q; i++) cin >> gQ[i].r >> gQ[i].c, r1 &= (gQ[i].r == 1);
		
		if (r1) BF1::Solve();
		else {
			for (int i = 1; i <= q; i++)
				cout << "0\n";
		}
		
		for (int i = 0; i < N; i++) gVec[i].clear(), gPos[i].clear();
	}
	
	return 0;
} 

/*
1#
1
3 3 3
5 1 2 3 4 1
3 1 2 5
3 5 1 6
1 2
1 4
1 1
*/
