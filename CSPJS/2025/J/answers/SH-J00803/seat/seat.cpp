#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[105];
bool cmp(int x, int y) {
	return x > y;
}int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n * m; i++) cin >> a[i];
	k = a[0];
	sort(a, a + n * m, cmp);
	for(int i = 0; i < n * m; i++) {
		if(a[i] == k) {
			cout << i / n + 1 << " ";
			if((i / n + 1) % 2 == 0) cout << (n + 1) - (i % n + 1);
			else cout << i % n + 1;
			break;
		}
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
