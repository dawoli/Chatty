#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 10;

int n, r[MAX_N];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &r[i]);
	sort(r + 1, r + n + 1);
	
	int ans = 0, pos = 1;
	for (int i = 1; i <= n; i++) {
		while (pos <= n && r[i] == r[pos]) pos++;
		if (pos == n + 1) break;
		ans++; pos++;
	}
	printf("%d\n", n - ans);
	
	return 0;
}
