#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 20) + 11;
int n, k, la[N], f[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	memset(la, 255, sizeof(la));
	la[0] = 0;
	for (int i = 1, Sum = 0; i <= n; i++) {
		int x;
		scanf("%d", &x);
		Sum ^= x;
		if (la[k ^ Sum] == -1)
			f[i] = f[i - 1];
		else
			f[i] = max(f[i - 1], f[la[k ^ Sum]] + 1);
		la[Sum] = i;
	}
	printf("%d\n", f[n]);
	return 0;
}
