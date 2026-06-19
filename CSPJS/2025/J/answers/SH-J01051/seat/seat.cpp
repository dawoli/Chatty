#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int a[N];
int main(){
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int cnt = 1;
	int R;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n * m; i++){
		if (i == 1) R = a[i];
		if (a[i] > R) cnt++;
	}
	int x, y;
	x = (cnt + n - 1) / n;
	y = ((cnt - 1) % n) + 1;
	cout << x << ' ';
	if (x % 2 == 1) cout << y << '\n';
	else cout << n - y + 1 << '\n';
	return 0;
}
