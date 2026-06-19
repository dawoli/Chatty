// seat

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

const int N = 1e3 + 10;
int gA[N];
PII gS[N];

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	
	int cnt = n * m;
	for (int i = 1; i <= cnt; i++)
		cin >> gA[i];
	
	int a = gA[1], r = 0, c = 1, dir = 1; sort(gA + 1, gA + cnt + 1, greater<int>());
	for (int i = 1; i <= cnt; i++) {
		if (1 <= r + dir && r + dir <= n) r += dir;
		else {
			c++;
			dir = -dir;
		}
		
		gS[i] = make_pair(r, c);
	}
	
	for (int i = 1; i <= cnt; i++)
		if (gA[i] == a) {
			cout << gS[i].second << " " << gS[i].first << endl;
			return 0; 
		}
	
	return 0;
}
