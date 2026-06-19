#include <bits/stdc++.h> 

using namespace std;

const int N = 1e5 + 10;
int mark[N];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		mark[x]++;
	}
	
	int mx = 0;
	for (int i = 1; i <= 100000; i++) {
		mx = max(mx, mark[i]);
	}
	
	printf("%d\n", mx);
	
	return 0;
}

