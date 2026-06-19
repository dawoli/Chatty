#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n;
string s[N]; 
signed main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout); 
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> s[i];
	sort(s + 1, s + n + 1);
	int cur = unique(s + 1, s + n + 1) - s - 1;
	cout << 52 - cur << endl;
	return 0;
} 
