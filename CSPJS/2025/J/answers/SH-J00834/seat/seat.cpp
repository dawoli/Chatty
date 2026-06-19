#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> scores;
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n * m; i++) {
		int tmp;
		cin >> tmp;
		scores.push_back(tmp);
	}
	int r = scores[0];
	sort(scores.begin(), scores.end(), greater<int>());
	int seat = 0;
	for(int i = 0; i < scores.size(); i++) {
		if(scores[i] == r) {
			seat = i;
			break;
		}
	}
	int col = seat / n;
	int row = (col % 2 == 0 ? seat % n : n - (seat % n) - 1);
	cout << col + 1 << ' ' << row + 1;
	return 0;
}
