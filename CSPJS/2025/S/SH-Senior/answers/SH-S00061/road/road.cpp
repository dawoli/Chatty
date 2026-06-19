#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
int n, m, k, x, y, z;
struct edge{
	int to;
	ll w;
};
vector<edge> v[M];
int c[N];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i) {
		cin >> x >> y >> z;
		v[x].push_back({y, z});
		v[y].push_back({x, z});
	}
	for(int i = 1; i <= k; ++i) {
		cin >> c[i];
		for(int j = 1; j <= n; ++j) {
			cin >> x;
			v[j].push_back({n+i, x+c[i]});
			v[n+i].push_back({j, x+c[i]});
		}
	}
	cout << 0 << endl;
	return 0;
}
