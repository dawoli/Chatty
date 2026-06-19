#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, m, q;
signed main()
{
	srand(time(0));
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	scanf("%lld", &t);
	while(t--){
		scanf("%lld %lld %lld", &n, &m, &q);
		while(q--){
			printf("%lld\n", rand() % 2);
		}
	}
	return 0;
}
