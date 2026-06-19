// CSP RP += 0x3f3f3f3f3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e5, M = 100;
int t, n, b[3], dp[M + 5][M + 5];
struct St{
	int y[3];
	pii a[3]; // haogandu, shetuan_number
	bool operator< (St o) const{
		if(a[0].first != o.a[0].first) return a[0].first > o.a[0].first;
		else if(a[1].first != o.a[1].first) return a[1].first > o.a[1].first;
		else return a[2].first > o.a[2].first;
	}
} s[N + 5];
ll ans;
set<pii, greater<pii> > sy[3];
set<pii, less<pii> > sg[3][3];
queue<pair<int, int> > tq;
queue<int> ti;

int mex(int a, int b){
	if(a > b) swap(a, b);
	return a == 0 ? b == 1 ? 2 : 1 : 0;
}

void solve1(){
	bool f = 1;
	b[0] = b[1] = b[2] = ans = 0;
	for(int i = 0; i < 3; ++ i){
		sy[i].clear();
		for(int j = 0; j < 3; ++ j) if(i != j) sg[i][j].clear();
	}
	for(int i = 1; i <= n; ++ i){
		for(int j = 0; j < 3; ++ j){
			cin >> s[i].y[j];
			s[i].a[j] = make_pair(s[i].y[j], j);
		}
		sort(s[i].a, s[i].a + 3, greater<pii>());
	}
	sort(s + 1, s + n + 1);
	for(int i = 1; i <= n; ++ i){
		for(int j = 0; j < 3; ++ j) if(b[s[i].a[j].second] < (n >> 1)){
			ans += s[i].a[j].first;
			++ b[s[i].a[j].second];
			sy[s[i].a[j].second].insert(make_pair(s[i].a[j].first, i));
			for(int k = 0; k < 3; ++ k) if(s[i].a[j].second != k) sg[s[i].a[j].second][k].insert(make_pair(s[i].a[j].first - s[i].y[k], i));
			break;
		}
	}
	while(f){
		f = 0;
		for(int t = 0; t < 3; ++ t){
			for(auto it = sy[t].begin(); it != sy[t].end(); ++ it){
				int u = it->second;
				for(int d = 0; d < 3; ++ d) if(t != d && s[u].y[d] > it->first){
					int df = s[u].y[d] - it->first;
					if(b[d] < (n >> 1)){
						++ b[d];
						-- b[t];
						ans += df;
						f = 1;
						tq.push(make_pair(u, d));
						break;
					}
					auto ni = sg[d][t].begin();
					if(df > ni->first){
						ans += df - ni->first;
						f = 1;
						ti.push(ni->second);
						sg[d][mex(d, t)].erase(make_pair(s[ni->second].y[d] - s[ni->second].y[mex(d, t)], ni->second));
						sy[d].erase(make_pair(s[ni->second].y[d], ni->second));
						sg[d][t].erase(ni);
						tq.push(make_pair(u, d));
						break;
					}
				}
			}
			while(!tq.empty()){
				int u = tq.front().first, d = tq.front().second;
				tq.pop();
				sy[t].erase(make_pair(s[u].y[t], u));
				for(int i = 0; i < 3; ++ i) if(i != t) sg[t][i].erase(make_pair(s[u].y[t] - s[u].y[i], u));
				sy[d].insert(make_pair(s[u].y[d], u));
				for(int i = 0; i < 3; ++ i) if(i != d) sg[d][i].insert(make_pair(s[u].y[d] - s[u].y[i], u));
			}
			while(!ti.empty()){
				int u = ti.front();
				ti.pop();
				sy[t].insert(make_pair(s[u].y[t], u));
				for(int i = 0; i < 3; ++ i) if(i != t) sg[t][i].insert(make_pair(s[u].y[t] - s[u].y[i], u));
			}
		}
	}
	cout << ans << '\n';
}

void dyp(){
	int a, b, c, ans = 0;
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; ++ i){
		cin >> a >> b >> c;
		for(int j = (n >> 1); j >= 0; -- j) for(int k = min(n >> 1, i - j); k >= max(0, i - (n >> 1) - j); -- k){
			int t = 0;
			if(j > 0) t = dp[j - 1][k] + a;
			if(k > 0) t = max(t, dp[j][k - 1] + b);
			if(i - j - k > 0) t = max(t, dp[j][k] + c);
			dp[j][k] = t;
			ans = max(ans, dp[j][k]);
		}
	}
	cout << ans << '\n';
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	while(t --){
		cin >> n;
		if(n <= 200) dyp();
		else solve1();
	}
}

