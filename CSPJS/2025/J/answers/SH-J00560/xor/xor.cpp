#include <bits/stdc++.h>
using namespace std;
const int NR = 5e5 + 10;
int a[NR];
//int s[NR];
struct Node {
	int l, r;
};
Node b[NR];
bool cmp(Node x, Node y) {
	return x.r < y.r;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] != 0 && a[i] != 1) flag = false;
//		s[i] = s[i - 1] ^ a[i];
	}
	if (k != 0 && k != 1) flag  = false;
	if (flag) {
		if (k == 1) {
			int cnt = 0;  
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1) cnt++;
			}
			cout << cnt << endl;
		}
		else {
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 0) cnt++;
				if (a[i] == 1 && a[i + 1] == 1) {
					cnt++;
					i++;
				}
			}
			cout << cnt << endl;
		}
		return 0;
	}
	int sz = 0;
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			int tmp = 0;
			for (int i = l; i <= r; i++) {
				tmp ^= a[i];
			}
			if (tmp == k) b[++sz] = {l, r};
		}
	}
//	for (int i = 1; i <= sz; i++) {
//		cout << b[i].l << " " << b[i].r << endl;
//	}
	sort(b + 1, b + 1 + sz, cmp);
	int ans = 1;
	int t = b[1].r;
	for (int i = 2; i <= sz; i++) {
		if (b[i].l > t) {
			t = b[i].r;
			ans++;
		}
	}
	printf("%d", ans);
	return 0; 
}
