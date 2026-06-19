#include<bits/stdc++.h>
using namespace std;

const int N = 5005, M = 998244353;
long long a[N], ans[N], f[N], an[N];

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	long long m = 0;
	for(int i = 1; i <= n; i++) m = max(m, a[i]);
	f[0] = 1;
	for(int i = 1; i <= n; ++i)
	{
		an[i] = an[i - 1] * 2 % M; 
		for(int j = m; j > m - a[i]; --j) an[i] = (an[i] + f[j]) % M;
		for(int j = m; j >= a[i]; --j) f[j] = (f[j] + f[j - a[i]]) % M;
		ans[i] = an[i];
		for(int j = m; j > a[i + 1]; --j) ans[i] += f[j]; 
	}
	long long as = 0;
	for(int i = 2; i < n; ++i) as = (ans[i] + as) % M;
	printf("%d", as);
}
