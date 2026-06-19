#include<bits/stdc++.h> 
using namespace std;
int t, n, m, l, V, d[100005], v[100005], a[100005], p[100005];
int main() {
	freopen("detect.in", "r", stdin); 
	freopen("detect.out", "w", stdout);
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cin >> n >> m >> l >> V;
		for(int j = 1; j <= n; j++) {
			cin >> d[i] >> v[i] >> a[i];
		}
		for(int j = 1; j <= m; j++) {
			cin >> p[i];
		}
		 
	}
	return 0;
}
