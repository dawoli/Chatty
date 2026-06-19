#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
const int m = 100000;
int n,a,cnt[N];
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a),++cnt[a];
	printf("%d\n", *max_element(cnt + 1, cnt + m + 1));
	return 0;
}