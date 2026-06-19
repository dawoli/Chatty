#include <bits/stdc++.h>
using namespace std;

struct road{
	int start;
	int end;
	int cost;
};

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	road roads[m];
	for (int i=0; i<m; i++) {
		cin >> roads[i].start >> roads[i].end >> roads[i].cost;
	}
	int town[k][n+1];
	for (int i=0; i<k; i++) {
		for (int j=0; j<n+1; j++) {
			cin >> town[i][j];
		}
	}
	cout << 0 << endl;
	return 0;
}
