#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N];
int j, cnt;
bool cmp(int x, int y) {
	return x < y;
}
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin.tie(0);
	cin >> n;
	cnt = n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n, cmp);
	j = 1;
	for(int i = 1; i <= n; i++) {
		while(j <= n && a[i] >= a[j]) j++;
		if(j > n) break;
		cnt--;
		j++;
		///cout << i << " " << j << endl;
	}
	cout << cnt;
	return 0;
}
