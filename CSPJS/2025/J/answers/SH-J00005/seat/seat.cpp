#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int N, M;
	cin >> N >> M;
	vector<int> A(N * M + 1);
	for(int i = 1; i <= N * M; i++) {
		cin >> A[i];
	}
	int score = A[1];
	
	sort(A.begin() + 1, A.end(), greater<>());
	int l = 1, r = N * M, rank = 1;
	while(l <= r) {
		int mid = (l + r) / 2;
		rank = mid;
		if(A[mid] < score) {
			r = mid - 1;
		}
		else if(A[mid] > score) {
			l = mid + 1;
		}
		else {
			break;
		}
	}
	
	int col = (rank - 1) / N + 1;
	int row = (rank - 1) % N + 1;
	if(col % 2 == 0) {
		row = N - row + 1;
	}
	cout << col << ' ' << row << '\n';
	
	return 0;
}
