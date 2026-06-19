#include <bits/stdc++.h>
using namespace std;
int box[100010], n;
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i=1;i<=n;i++) {
		int t;
		cin >> t;
		box[t]++;
	}
	int maxn = -1;
	for(int i=1;i<=n;i++) {
		maxn = max(maxn, box[i]);
	}
	cout << maxn << endl;
	return 0;
} 
