#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 3, R = 102, V = 200003;
vector<int> s[N];
int T, n, k, q;
vector<bool> dp[R][N];

struct Point {
	int x, y, t;
};
queue<Point> qp;
vector<Point> sm[V];
struct Query {
	int r, c;
};
vector<Query> qr;

void test() {
	cin >> n >> k >> q;
	for(int i=1; i<=n; i++) s[i].clear();
	int maxv = 0;
	for(int i=1, l; i<=n; i++) {
		cin >> l; int v;
		for(int t=0; t<l; t++) 
			cin >> v, maxv = max(v, maxv), s[i].push_back(v);
	}
	for(int i=1; i<=maxv; i++) sm[i].clear();
	for(int i=1; i<=n; i++) for(int t=0; t<s[i].size(); t++) sm[s[i][t]].push_back((Point){i, t, 0});
	qr.clear();
	int maxr = 0; 
	for(int i=0, r, c; i<q; i++) cin >> r >> c, maxr = max(r, maxr), qr.push_back((Query){r, c});
	for(int i=1; i<=maxr; i++) for(int j=1; j<=n; j++) dp[i][j].clear();
	for(int r=0; r<=maxr; r++) for(int i=1; i<=n; i++) for(int t=0; t<s[i].size(); t++) 
		dp[r][i].push_back(0);
	for(int i=0; i<sm[1].size(); i++) qp.push(sm[1][i]);
	while(!qp.empty()) { 
		Point np = qp.front(); qp.pop();
		if(np.t >= maxr) continue;
		int x = np.x, y = np.y;
//		cout << x << ' ' << y << ' ' << np.t << endl;
		for(int i=1; y+i<s[x].size() and i+1<=k; i++) {
			int nx = x, ny = y + i;
//			cout << np.t << " NX, NY: " << nx << ' ' << ny << endl;
			if(dp[np.t + 1][nx][ny]) continue;
			dp[np.t + 1][nx][ny] = true;
			int v = s[nx][ny];
			for(int j=0; j<sm[v].size(); j++) {
				int nnx = sm[v][j].x, nny = sm[v][j].y;
				if(nnx == nx) continue; 
//				cout << "NNX, NNY: " << nnx << ' ' << nny << endl;
				Point nnp;
				nnp.x = nnx, nnp.y = nny, nnp.t = np.t + 1;
				qp.push(nnp); 
			}
		} 
	}
	for(int i=0; i<q; i++) {
		int r = qr[i].r, c = qr[i].c;
		bool ok = false;
		for(int i=0; i<sm[c].size(); i++) {
			int x = sm[c][i].x, y = sm[c][i].y;
			ok = ok | dp[r][x][y];
		}
		cout << ok << endl;
	}
}

int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	cin >> T;
	while(T--) test();
	return 0;
}

/*
1
3 3 7
5 1 2 3 4 1
3 1 2 5
3 5 1 6
1 2
1 4
2 4
3 4
6 6
1 1
7 7
*/
 
