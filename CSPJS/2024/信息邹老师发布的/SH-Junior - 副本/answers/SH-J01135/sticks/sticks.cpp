#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin >> t;
	for (int i = 1;i <= t;i++){
		int n;
		cin >> n;
		if (n == 1) cout << -1 << endl;
		else if (n == 3) cout << 7 << endl;
		else if (n == 4) cout << 4 << endl;
		else {
			int d = n%7;
			int ans = 0;
			if (d == 0) {
				for (int j = 1;j <= n/7;j++){
					ans = ans*10+8;
				}
			}
			else if (d == 1) {
				ans = 10;
				for (int j = 1;j <= n/7-1;j++){
					ans = ans*10+8;
				}
			}
			else if (d == 2) {
				ans = 1;
				for (int j = 1;j <= n/7;j++){
					ans = ans*10+8;
				}
			}
			else if (d == 3) {
				ans = 23;
				for (int j = 1;j <= n/7-1;j++){
					ans = ans*10+8;
				}
			}
			else if (d == 4) {
				ans = 20;
				for (int j = 1;j <= n/7-1;j++){
					ans = ans*10+8;
				}
			}
			else if (d == 5) {
				ans = 2;
				for (int j = 1;j <= n/7;j++){
					ans = ans*10+8;
				}
			}
			else {
				ans = 6;
				for (int j = 1;j <= n/7;j++){
					ans = ans*10+8;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
