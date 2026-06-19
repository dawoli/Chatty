#include <bits/stdc++.h>
using namespace std; 
const int N = 1e5 + 10;
int n, cnt [N];
int main () {
	freopen ("duel.in", "r", stdin);
	freopen ("duel.out", "w", stdout); 
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		int tmp;
		cin >> tmp;
		cnt [tmp] ++;
	}
	int maxn = -1;
	for (int i = 0; i <= 1e5; i ++)
		maxn = max (maxn, cnt [i]);
	cout << maxn;
}