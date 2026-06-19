#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k, f[20000], a[2000000], b[2000000], c[2000000], w[20], d[20][10005];
vector<pair<int, int> >val;
vector<pair<int, int> >g;
vector<pair<int, int> >s;
int find(int x){
	if (f[x] == x){
		return x;
	}
	f[x] = find(f[x]);
	return f[x];
}
void bin(int x, int y){
	int fx = find(x), fy = find(y);
	f[fx] = fy; 
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		cin >> a[i] >> b[i] >> c[i];
		val.push_back({c[i], i});
	}
	for (int i = 1; i <= n; i++){
		f[i] = i;
	}
	sort(val.begin(), val.end());
	for (int i = 0; i < val.size(); i++){
		int now = val[i].second;
		int cst = val[i].first;
		if (find(a[now]) != find(b[now])){
			bin(a[now], b[now]);
			g.push_back({cst, now});
		}
	}
	for (int i = 0; i < k; i++){
		cin >> w[i];
		for (int j = 1; j <= n; j++){
			cin >> d[i][j];
		}
	}
	int ans = 1e18;
	for (int i = 0; i < (1 << k); i++){
		s.clear();
		for (int j = 0; j < g.size(); j++){
			s.push_back(g[j]);
		}
		int tmp = 0, tot = m;
		for (int j = 0; j < k; j++){
			if (i >> j & 1){
				tmp += w[j];
				for (int u = 1; u <= n; u++){
					tot++;
					a[tot] = n + j + 1;
					b[tot] = u;
					c[tot] = d[j][u];
					s.push_back({c[tot], tot});
				}
			}
		}
		sort(s.begin(), s.end());
		for (int j = 1; j <= n + k; j++){
			f[j] = j;
		}
		for (int j = 0; j < s.size(); j++){
			int now = s[j].second;
			int cst = s[j].first;
			if (find(a[now]) != find(b[now])){
				bin(a[now], b[now]);
				tmp += c[now];
			}
		}
		ans = min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
} 
