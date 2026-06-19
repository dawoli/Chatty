#include <bits/stdc++.h>
using namespace std;
int n, a[100005], c[100005], nmax;
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		int t;
		scanf("%d", &t);
		a[t]++;
		nmax = max(nmax, t);
	}
	for (int i = 1; i <= nmax; i++){
		if (a[i] >= c[i - 1]) c[i] = a[i];
		else c[i] = c[i - 1];
	}
	printf("%d", c[nmax]);
	return 0;
}
