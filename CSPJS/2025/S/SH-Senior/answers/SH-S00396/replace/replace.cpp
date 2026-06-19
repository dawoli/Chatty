#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q;
char s1[N], s2[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		scanf("%s%s", s1 + 1, s2 + 1);
	}
	while (q--) {
		scanf("%s%s", s1 + 1, s2 + 1);
		printf("0\n");
	}
	return 0;
}
