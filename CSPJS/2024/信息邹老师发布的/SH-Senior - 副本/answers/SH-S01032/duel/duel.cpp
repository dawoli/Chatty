#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
struct Node {
	int a, b;
} a[100005];
bool operator < (Node x, Node y) {
	return x.a < y.a;
}
bool vis1[100005], vis2[100005];

int find(int l, int r, int i) {
	int ret = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (a[mid].a > a[i].b) r = mid - 1, ret = mid;
		else l = mid + 1;
	}
	while (vis1[ret]) ret++;
	return ret;
}

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].a);
		a[i].b = a[i].a;
	}
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i++) {
		int pos = find(i + 1, n, i);
		if (pos != -1) {
			vis2[i] = true;
			vis1[pos] = true;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (!vis1[i]) cnt++;
	cout << cnt << endl;
	return 0;
}
