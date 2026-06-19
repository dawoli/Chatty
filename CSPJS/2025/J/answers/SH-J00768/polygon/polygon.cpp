#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int a[5010];
int ans;

void DFS(int pos, int left, int num, int maxi) {  
	if (left == 0) {
		if (num > maxi * 2) ans = (ans + 1) % 998244353;
		return;
	}
	if (pos > n) return;
	for (int i = pos; i <= n - (left - 1); i++) 
		DFS(i + 1, left - 1, num + a[i], max(maxi, a[i]));
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	for (int i = 3; i <= n; i++) DFS(1, i, 0, 0);
	cout << ans << endl;
	return 0;
}
