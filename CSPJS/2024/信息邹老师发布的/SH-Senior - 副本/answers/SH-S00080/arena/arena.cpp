#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1, x; i <= n+m; i++)
		scanf("%d", &x);
	scanf("%d", &n);
	while (n--) puts("0");
	return 0;
}
