#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

int stick[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int f[100005];
int T;

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	scanf("%d", &T);
	memset(f, 0x3f, sizeof(f));
	f[2] = 1, f[3] = 7, f[4] = 4, f[5] = 2, f[6] = 6, f[7] = 8;
	for (int i = 1; i <= T; i++) {
		int n;
		scanf("%d", &n);
		if (n == 1) {
			printf("-1\n");
			continue;
		} 
		else {
			for (int j = 2; j <= n; j++) {
				if (f[j] != 0x3f3f3f3f) continue;
				for (int k = 0; k <= 9; k++) {
					f[j] = min(f[j], f[max(0, j - stick[k])] * 10 + k);
				}
			}
			if (f[n] != 0x3f3f3f3f) printf("%d\n", f[n]);
			else printf("-1\n");
		}
	}
	return 0;
}
