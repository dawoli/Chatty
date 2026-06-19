#include <bits/stdc++.h>
using namespace std;
int n, m, s[110];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> s[i];
	int a = s[1], pos;
	sort(s + 1, s + n * m + 1);
	for(int i = 1; i <= n * m; i++)
		if(s[i] == a) {pos = n * m - i + 1; break;}
	int x = pos / n, y;
	if(pos % n == 0) {
		if(x % 2 == 0) y = 1;
		else y = n;
	}
	else {
		x++;
		if(x % 2 == 0) y = n - pos % n + 1;
		else y = pos % n;
	}
	cout << x << " " << y << "\n";
	return 0;
}
