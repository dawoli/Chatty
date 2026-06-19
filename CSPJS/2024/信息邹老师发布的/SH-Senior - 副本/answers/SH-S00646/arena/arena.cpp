#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int n, m, T, K, A[200010], c[200010], d[20][100010], a[200010], X[10], win[20][200010];
int main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
	for(int i = 1; i <= m; i++) {
		scanf("%d", &c[i]);
	}
	int tmpN = 1;
	while(tmpN < n) {
		tmpN *= 2;
		K++;
	}
	for(int k = 1; k <= K; k++) {
		string str;
		cin >> str; 
		for(int j = 1; j <= (1 << (K - k)); j++) {
			d[k][j] = str[j - 1] - '0';
		}
	}
	scanf("%d", &T);
	while(T--) {
		int X0, X1, X2, X3;
		scanf("%d %d %d %d", &X[0], &X[1], &X[2], &X[3]);
		for(int i = 1; i <= n; i++) {
			a[i] = A[i] ^ X[i % 4];
			win[0][i] = i;
		}
		for(int j = 1; j <= K; j++) {
			for(int p = 1; p <= tmpN / (1 << j); p++) {
				if(d[j][p]) {
					win[j][p] = (a[win[j - 1][p * 2]] >= j ? win[j - 1][p * 2] : win[j - 1][p * 2 - 1]);
				} else {
					win[j][p] = (a[win[j - 1][p * 2 - 1]] >= j ? win[j - 1][p * 2 - 1] : win[j - 1][p * 2]);
				}
			}
		}
		long long ans = 0;
		for(int i = 1; i <= m; i++) {
			int tmpC = 1, k = 0;
			while(tmpC < c[i]) {
				tmpC *= 2;
				k++;
			}
			ans ^= (1ll * i * win[k][1]); 
		}
		printf("%d\n", ans);
	}
    return 0;
}
