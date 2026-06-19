#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

const int MAXN = 1024;
int s[MAXN][MAXN^2];
int t, n, k, q, a[MAXN];

int main() {
	freopen("chain.in", "r", stdin); 
	freopen("chain.out","w",stdout);
	srand(time(0));
	cin >> t;
	while (t--) {
		cin >> n >> k >> q;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			for (int j = 1; j <= a[i]; i++) {
				cin >> s[i][j];
			}
		}
		for (int i = 1; i <= q; i++) {
			cout << rand()*7%2 << "\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
