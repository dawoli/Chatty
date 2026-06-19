#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

int T;
int n, k, q;
int s[1003][2003];
int l[1003];
int cnt[200005];

int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &k, &q);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &l[i]);
			for (int j = 1; j <= l[i]; j++)
				scanf("%d", &s[i][j]), cnt[s[i][j]]++;
		}
		for (int i = 1; i <= q; i++) {
			int r, c;
			scanf("%d%d", &r, &c);
			if (!cnt[c]) {
				printf("0\n");
				continue;
			}
			if (r <= 1) {
				if (!cnt[c]) {
					printf("0\n");
					continue;
				}
				bool flag = 0;
				for (int j = 1; j <= n; j++) {
					for (int p = 1; p <= l[j]; p++) {
						if (s[j][p] == c) {
							for (int x = p - 1; x >= 1; x--) {
								if (s[j][x] == 1 && p - x + 1 <= k) {
									flag = 1;
									break;
								}
							}
						}
						if (flag) break;
					}
					if (flag) break;
				}
				if (flag) printf("1\n");
				else printf("0\n");
			}
		}
	}
	return 0;
}
