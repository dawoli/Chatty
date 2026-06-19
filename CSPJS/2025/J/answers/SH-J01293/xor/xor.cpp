#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int A[500005], B[500005];
int n, j, k, ss;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", A + i);
		B[i] = B[i - 1] ^ A[i];
	}
	for (int i = 1; i <= n; i++)
		for (int q = i - 1; q >= j; q--)
		{
			if ((B[i] ^ B[q]) == k)
			{
				ss++;
				j = i;
				break;
			}
		}
	printf("%d\n", ss);
	return 0;
}
