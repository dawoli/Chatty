// duel

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 10;
int gA[N];

signed main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> gA[i];
	
	sort(gA + 1, gA + n + 1);
	
	int l = 1, ans = n; multiset<int> se; se.insert(gA[1]);
	for (int r = 2; r <= n; r++) {
		if (!se.empty()) {
			auto it = se.begin();
			if (*it < gA[r]) se.erase(it), ans--;
		} se.insert(gA[r]);
	}
	
	cout << ans << endl;
	return 0;
} 

/*
NOTE: 
lyx loves dzh
hxd loves xxx
xxx loves jxy
It`s a sweet story.
*/
