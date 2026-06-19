#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n, rList[MAXN];
int main () {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &rList[i]);
	sort(rList + 1, rList + n + 1);
	int i = 1;
	for (int j = 1; j <= n; i ++, j ++) {
		bool outFlag = false;
		while (rList[i] >= rList[j]) {
			if (j ++ > n) {
				outFlag = true;
				break;
			}
		}
		if (outFlag) break;
	}
	printf("%d", n - i + 1);
    return 0;
}
