#include <bits/stdc++.h>
using namespace std;
int n, m, Rscore;
vector<int> score;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1, num; i <= n * m; ++i) {
		cin >> num;
		if (i == 1) Rscore = num;
		score.push_back(num);
	}
	sort(score.begin(), score.end());
	// int num = score.back();
	// score.pop_back();
	for (int j = 0; j < m; ++j) {
		// ÆæÊýÁÐ 
		if (j == 0 || j % 2 == 0) {
			for (int i = 0; i < n; ++i) {
				if (score.back() == Rscore) {
					cout << j + 1 << " " << i + 1; // 1-based
					return 0;
				}
				score.pop_back();
			}
		}
		else {
			for (int i =  n - 1; i >= 0; --i) {
				if (score.back() == Rscore) {
					cout << j + 1 << " " << i + 1;
					return 0;
				}
				score.pop_back();
			}
		}
	}
	return 0;
} 
