#include <iostream>
#include <vector>
using namespace std;
const int MAX_VAL = 90000;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<vector<int>> matrix(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}
	vector<int> cnt(MAX_VAL, 0);
	int unique = 0;
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < k; ++j) {
			int val = matrix[i][j];
			if (cnt[val]++ == 0) {
				unique++;
			}
		}
	}
	vector<vector<int>> result(n - k + 1, vector<int>(n - k + 1));
	result[0][0] = unique;
	for (int j = 1; j <= n - k; ++j) {
		for (int i = 0; i < k; ++i) {
			int val = matrix[i][j - 1];
			if (--cnt[val] == 0) {
				unique--;
			}
		}
		for (int i = 0; i < k; ++i) {
			int val = matrix[i][j + k - 1];
			if (cnt[val]++ == 0) {
				unique++;
			}
		}
		result[0][j] = unique;
	}
	for (int i = 1; i <= n - k; ++i) {
		for (int j = 0; j < k; ++j) {
			int val = matrix[i - 1][j];
			if (--cnt[val] == 0) {
				unique--;
			}
		}
		for (int j = 0; j < k; ++j) {
			int val = matrix[i + k - 1][j];
			if (cnt[val]++ == 0) {
				unique++;
			}
		}
		result[i][0] = unique;
		for (int j = 1; j <= n - k; ++j) {
			for (int row = i; row < i + k; ++row) {
				int val = matrix[row][j - 1];
				if (--cnt[val] == 0) {
					unique--;
				}
			}
			for (int row = i; row < i + k; ++row) {
				int val = matrix[row][j + k - 1];
				if (cnt[val]++ == 0) {
					unique++;
				}
			}
			result[i][j] = unique;
		}
	}
	for (const auto& row : result) {
		for (int num : row) {
			cout << num << ' ';
		}
		cout << '\n';
	}
	return 0;
}
