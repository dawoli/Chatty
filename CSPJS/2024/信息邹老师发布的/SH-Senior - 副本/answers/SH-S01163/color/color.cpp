#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200100
int T;
int n, A[N], C[N];
void _() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> A[i];
	if(n <= 15) {
		int maxx = -1;
		for(int S = 0; S < (1 << n); S++) {
			memset(C, 0, sizeof C);
			for(int i = 1; i <= n; i++) {
				for(int j = i - 1; j; j--) {
					if(((S >> j - 1) & 1) == ((S >> i - 1) & 1))
						if(A[i] == A[j]) C[i] = A[i]; 
				}
			}
			int ans = 0;
			for(int i = 1; i <= n; i++)
				ans += C[i];
			maxx = max(maxx, ans);
		}
		cout << maxx << endl;
	}
}

signed main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	for(cin >> T; T--; _());
	return 0;
}