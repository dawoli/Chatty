#include <bits/stdc++.h> 
using namespace std;
const int N = 5e5+10;
long long n, k, a[N], b[N], dp[N], d[N];
struct node {
	int id, pre;
}c[N];
bool cmp(node a, node b) {
	if(a.pre == b.pre) return a.id > b.id;
	return a.pre < b.pre;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout); 
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		c[i].pre = c[i-1].pre ^ a[i];
		b[i] = c[i].pre;
		c[i].id = i;
	}
	c[0].id = c[0].pre = 0;
    sort(c, c+n+1, cmp);
    for(int i = 0; i <= n; i++) d[i] = c[i].pre;
	for(int i = 1; i <= n; i++) { 
		dp[i] = dp[i-1];
		int x = b[i]^k;
		int j = lower_bound(d+1, d+n+1, x)-d;
		if(d[j] != x) continue;
		while(c[j].id >= i && d[j+1] == x) j++;
		if(c[j].id >= i) continue;
		dp[i] = max(dp[i], dp[c[j].id]+1);
	}
	cout << dp[n];
	return 0;
}
