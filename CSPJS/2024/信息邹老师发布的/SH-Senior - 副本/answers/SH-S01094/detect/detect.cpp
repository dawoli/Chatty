#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, L, V; 
int a [N], D [N], v [N], p [N];
int main () {
	freopen ("detect.in", "r", stdin);
	freopen ("detect.out", "w", stdout);
	int T;
	cin >> T;
	while (T --) {
		cin >> n >> m >> L >> V;
		for (int i = 1; i <= n; i ++)
			cin >> d [i] >> v [i] >> a [i];
		for (int i = 1; i <= m; i ++) cin >> p [i];
		sort (p + 1, p + n + 1);
		for (int i = 1; i <= n; i ++) {
			if (a [i] > 0) {
				int k = (V - v [i]) / a [i];
				if ((V - v [i]) % a [i] != 0) k ++;
				int r = k * v [i] + d [i]; 
			}
		}
	}
}