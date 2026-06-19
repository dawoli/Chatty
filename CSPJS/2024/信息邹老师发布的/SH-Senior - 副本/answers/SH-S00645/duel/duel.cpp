#include <iostream>
#include <algorithm>
using namespace std;
struct mon
{
	int r, i;
	bool b;
	
}r[100010];
bool operator < (mon m1, mon m2)
{
	return m1.r < m2.r;
}
int n;
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &r[i].r);
		r[i].i = i;
	}
	sort(r + 1, r + n + 1);
	int nb = 0;
	for(int i = 1; i <= n; i++)
	{
		int curr = upper_bound(r + 1, r + n, r[i]) - lower_bound(r + 1, r + n, r[i]);
		i = upper_bound(r + 1, r + n, r[i]) - r + 1;
		int tmp = curr >= nb ? 0 : nb - curr;
		nb = tmp + curr;
	}
	printf("%d", nb);
	return 0;
} 
