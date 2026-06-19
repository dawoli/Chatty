#include <bits/stdc++.h> // 期望得分：100 
using namespace std ;

int n, m ;
int r, g = 1, t ;
int main()
{
	freopen("seat.in", "r", stdin) ;
	freopen("seat.out", "w", stdout) ;
	scanf("%d %d", &n, &m) ;
	scanf("%d", &r) ;
	for (int i = 2; i <= n * m; i++)
	{
		scanf("%d", &t) ;
		g += int(t > r) ;
	}
	if ((int)ceil(1.0 * g / n) % 2 == 1)
	{
		printf("%d %d", (int)ceil(1.0 * g / n), (g - 1) % n + 1) ;
	}
	else
	{
		printf("%d %d", (int)ceil(1.0 * g / n), n - ((g - 1) % n + 1) + 1) ;
	}
	return 0 ;
}
