#include <bits/stdc++.h>
using namespace std;
bool killed[100010];
int r[100010];
int n;
int ans;
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &r[i]);
	sort(r + 1, r + n + 1);
	int j = 1;
	for(int i = 1; i <= n; i++)
	{
		j++;
		while(r[j] <= r[i] && j <= n) j++;
		if(j == n + 1) break;
		killed[i] = true;
	}
	for(int i = 1; i <= n; i++)
		ans += !killed[i];
	printf("%d", ans);
	return 0;
}
