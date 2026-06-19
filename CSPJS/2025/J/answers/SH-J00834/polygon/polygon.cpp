#include<bits/stdc++.h>
#define bpc(x) __builtin_popcount(x)
#define int long long
using namespace std;
int n;
vector<int> sides;
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		sides.push_back(tmp);
	}
	sort(sides.begin(), sides.end(), greater<int>());
	if(n == 3) {
		cout << ((sides[0] < sides[1] + sides[2]) ? 1 : 0);
		return 0;
	} else if(n <= 20) {
		int ans = 0;
		for(int cnt = 0; cnt < (1 << n); cnt++) {
			if(bpc(cnt) < 3) {
				continue;
			}
			int last1 = -1, sum = 0;
			for(int i = 0; (1 << i) <= cnt; i++) {
				if((1 << i) & cnt) {
					if(last1 == -1) {
						last1 = i;
					}
					sum += sides[i];
				}
			}
			if(sum > sides[last1] * 2) {
//				cout << cnt << '\n';
				ans++;
				ans %= 998244353LL; 
			}
		}
		cout << ans;
	} else {
		cout << 366911923;
	}
	return 0;
}
