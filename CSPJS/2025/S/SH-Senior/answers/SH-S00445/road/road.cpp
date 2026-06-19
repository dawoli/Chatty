#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int u[100005], v[100005], w[100005], c[10][10000];
int a[100005];
int main () {
	freopen("road.in","r",stdin);
	freopen("road.out","w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m ; i++) {
		cin >> u[i] >> v[i] >> w[i];
	} 
//	for(int i = 1; i <= k; i++) {
//		for(int i = 1; i <= n + 1; i++) {
//			cin >> c[i][j];
//		}
//	}
long long sum =0;
	for(int i = 1; i <= m - 1; i++) {
		sum = (w[i]+ w[i + 1], sum);
	}
	cout << sum << endl;
	return 0;
}

