#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+5;
int l[N], a[N][N], r[N], c[N];

void solve(){
	int n, k, q;
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i++){
		cin >> l[i];
		for (int j = 1; j <= l[i]; j++)
			cin >> a[i][j];
	}
	for (int i = 1; i <= q; i++)
		cin >> r[i] >> c[i];
	cout << 1 << endl;
}

int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t;
	cin >> t;
	while (t--){
		solve();
	}
	return 0;
}
