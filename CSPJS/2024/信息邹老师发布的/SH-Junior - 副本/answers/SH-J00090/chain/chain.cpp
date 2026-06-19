#include <bits/stdc++.h>
using namespace std;
int t , n , k , q , l [300000] , s [1005] [1005] , r [300000] , c [300000];
int main () {
	freopen ("chain.in" , "r" , stdin);
	freopen ("chain.out" , "w" , stdout);
	for (cin >> t;t;t --) {
		cin >> n >> k >> q;
		for (int i = 0;i < n;i ++) {
			cin >> l [i];
			for (int j = 0;j < l [i];j ++) cin >> s [i] [j];
		}
		for (int i = 0;i < q;i ++) {
			cin >> r [i] >> c [i];
			cout << (c [i] < r [i] + 1) << endl;
		}
	}
	return 0;
}
