#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 510;
const int mod = 998244353;

int n, m, c[MAX_N], p[MAX_N];
char str[MAX_N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, str + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]), p[i] = i;
	int res = 0;
	do {
		int ac = 0, wa = 0;
		for (int i = 1; i <= n; i++) {
			if (wa >= c[p[i]] || str[i] == '0') wa++;
			else ac++;
		}
		res = (res + (ac >= m)) % mod;
	} while (next_permutation(p + 1, p + n + 1));
	printf("%d\n", res);
	return 0;
} 
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
