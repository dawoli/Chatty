#include <bits/stdc++.h>
using namespace std;

int n, ans;
set<string> pok;

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		string p;
		cin >> p;
		pok.insert(p);
	}
	
	ans = 52 - pok.size();
	cout << ans << endl;
	return 0;
}
/*
4
DQ
H3
DQ
DT
*/
