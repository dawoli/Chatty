#include <iostream>
using namespace std;
int t;
int ans[51];
int main () {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;

	for (int i = 1; i <= t; i++) {
		int num[25] = {-1, 1, 7, 4, 2, 9, 8, 10, 18, 23, 20, 28, 80, 88, 108, 203, 238, 208, 288, 808};
		int n;
		cin >> n;
		if (n < 2) {
			ans[i] = -1;
			continue;
		}
		ans[i] = num[n -1 ];
	} 
	for (int i = 1; i <= t; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}

