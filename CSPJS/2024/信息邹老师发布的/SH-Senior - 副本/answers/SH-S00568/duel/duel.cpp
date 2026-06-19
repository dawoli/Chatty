#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>


using namespace std;

int n, r[100005];
int cnt[100005];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &r[i]);
	for (int i = 1; i <= n; i++) cnt[r[i]]++;
	int maxn = 0;
	for (int i = 1; i <= n; i++) maxn = max(maxn, cnt[r[i]]);
	printf("%d", maxn);
	return 0;
}
