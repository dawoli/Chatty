#include <bits/stdc++.h>
using namespace std;

const int N=1e5+2;
int mst[N]={0};
int n;
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", mst+i);
	sort(mst, mst+n+1);
	int j=1, res=n;
	for (int i=1; i<n; i++) {
		while (j <= n && mst[j] <= mst[i])
			j++;
		if (j <= n)
			res--;
		if (j >= n)
			break;
		j++;
	}
	printf("%d", res);
	return 0;
}
