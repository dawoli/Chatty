#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
#define Mod 998244353
using namespace std;
ll A[5005], B[5005], DP[5005][5005], M[5005][5005], n, j;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", A + i);
		B[i] = B[i - 1] + A[i];
	}
	memset(M, -63, sizeof (M));
	for (int i = 1; i <= n; i++)
		M[i][i] = A[i];
	for (int i = 1; i < n; i++)
		M[i][i + 1] = M[i + 1][i] = max(A[i], A[i + 1]);
	for (int k = 3; k <= n; k++)
		for (int i = 1; i <= n - k + 1; i++)
		{
			j = i + k - 1;
			M[i][j] = M[j][i] = max(M[i + 1][j], M[i][j - 1]);
			DP[i][j] = (DP[i + 1][j] + DP[i][j - 1]) % Mod;
			for (int k = i + 1; k < j; k++)
				DP[i][j] = (DP[i][j] + DP[i][k - 1] + DP[k + 1][j]) % Mod;
			if (B[j] - B[i - 1] > M[i][j] * 2)
				DP[i][j] = (DP[i][j] + 1) % Mod;
		}
	printf("%lld\n", DP[1][n]);
	return 0;
}
