#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+114, stck[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int ans = -1; 
int f(int numb) {
	int ret = 0;
	while(numb != 0) {
		ret++; numb /= 10;
	}
	return ret;
}
void dfs(long long numb, int ws, int n) {
	if (n == 1) return;
	if (n == 0) { 
		if (f(numb) != ws) return;
		if (ans < 0 || numb < ans) ans = numb;
		return;
	}
	else {
		for (int i = 0; i <= 9; i++) {
			if (n >= stck[i]){
				numb += pow(10, ws) * i;
				ws++;
				n -= stck[i];
				if(ans == -1 || numb < ans) 
				dfs(numb, ws, n);
				n += stck[i];
				ws--;
				numb -= pow(10, ws) * i;
			}
		}
	}
}
int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		int n; cin >> n;
		ans = -1;
		if (n % 7 == 0 && n >= 100) {
			for (int i = 1; i <= n / 7; i++) {
				cout << 8;
			}
			cout << endl;
			continue;
		}
		if ((n - 1) % 7 == 0 && n >= 100) {
			cout << 10;
			for(int i = 1; i <= (n - 8) / 7; i++) {
				cout << 8;
			}
			cout << endl;
			continue;
		}
		dfs(0LL, 0, n);
		cout << ans << endl;
	}
	return 0;
} 
