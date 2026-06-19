#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, a[N], cnt[N]; 
inline void optimizeIO(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
}
int main(int argc, const char *argv[]) {
#ifndef LOCAL
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
#endif
	optimizeIO(), cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i], ++cnt[a[i]];
	}
	cout << *max_element(cnt, cnt + N) << endl;
	return 0;
} 
/*
I love yjy forever.
God bless no fst.
*/
