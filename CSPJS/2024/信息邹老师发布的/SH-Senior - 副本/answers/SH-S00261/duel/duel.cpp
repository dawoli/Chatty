#include <bits/stdc++.h>
using namespace std;

int n, p, r[1000001];
int sum, maxr;

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &p);
		r[p] += 1;
		maxr = max(maxr, p);
	}
	for(int i = 1; i <= maxr; i++) sum = max(r[i], sum);
	printf("%d", sum);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
