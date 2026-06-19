#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node {
	int id, x;
}a[101], l[101];
bool cmp(node u, node v) {
	return u.x > v.x;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].x;
		a[i].id = i;
	}
	sort(a + 1, a + 1 + n * m, cmp);
	int i = 1, j = 1;
	for (int cnt = 1; cnt <= n * m; cnt++) {
		l[a[cnt].id] = {i, j};
		if (i == n && j % 2 || i == 1 && !(j % 2)) j++;
		else {
			if (j % 2) i++;
			else i--;
		}
	}
	cout << l[1].x << ' ' << l[1].id << '\n';
	return 0;
} 
