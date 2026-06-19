#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 15;

int n, m, a[N * N];

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(nullptr), cout.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m;
	for(int i = 1; i <= n * m; ++i) cin >> a[i];

	int val = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	int x = 1, y = 1;
	for(int i = 1; i <= n * m; ++i) {
		if(a[i] == val) {
			cout << y << " " << x << "\n";
			return 0;
		}
		if(y & 1) x++;
		else x--;
		if(x > n) x = n, y++;
		if(x < 1) x = 1, y++;
	}

	return 0;
}
