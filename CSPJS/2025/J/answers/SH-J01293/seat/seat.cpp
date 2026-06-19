#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int n, m, A[105], u, r, c;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m * n; i++)
		scanf("%d", A + i);
	u = A[1]; 
	sort(A + 1, A + 1 + m * n, greater <int> ());
	for (int i = 1; i <= m * n; i++)
		if (A[i] == u)
		{
			c = (i - 1) / m + 1;
			if (c % 2)
				r = (i - 1) % m + 1;
			else
				r = m - (i - 1) % m;
			printf("%d %d\n", c, r);
			break;
		}
	return 0;
}
