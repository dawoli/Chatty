#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

//int d[N];

int main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	int players[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> players[i];
	}
	
	int c[n+1];
	int maxc = 0;
	for (int i = 0; i < m; i++) {
		cin >> c[i];
		maxc = max(maxc, c[i]);
	}
	
	int K = 0;
	while (pow(2, K) < n) {
		K += 1;
	}
	int total = pow(2, K);
	
	/*for (int R = 1; R <= K; R++) {
		for (int G = 1; G <= pow(2, K - R); G++) {
			cin >> d[R][G];
		}
	}*/
	
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int X0, X1, X2, X3;
		int powers[n+1];
		for (int i = 1; i <= n; i++) {
			if (i % 4 == 0) {
				powers[i] = players[i] ^ X0;
			}
			else if (i % 4 == 1) {
				powers[i] = players[i] ^ X1;
			}
			else if (i % 4 == 2) {
				powers[i] = players[i] ^ X2;
			}
			else {
				powers[i] = players[i] ^ X3;
			}
		}
		
		/*for (int i = 1; i <= maxc; i++) {
			for (int r = 1; r <= K; r++) {
				for (int g = 1; g * r <= K; g++) {
				}
			}
		}*/
	}
	return 0;
}
