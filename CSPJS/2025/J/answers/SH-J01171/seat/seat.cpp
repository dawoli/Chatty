#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);
	
	int score; 
	scanf("%d", &score);
	int tmp; 
	int rank = 1;
	for (int i = 2; i <= m*n; ++i) {
		scanf("%d", &tmp);
		if (tmp > score) rank++;
	}
	
	// cout << rank << endl;
	
	// 1) x = 1~n mod 2n
	// row x%2n col ceil(x/n)
	// 2) x = n+1~2n mod 2n
	// row (n+1-x%n) col ceil(x/n)
	if (rank % (2*n) >= 1 && rank % (2*n) <= n) {
		// cout << "@1" << endl;
		int col = ceil(float(rank) / n);
		int row = (rank % n == 0 ? n : rank % n);
		printf("%d %d", col, row);
	} 
	else {
		// cout << "@2" << endl;
		int col = ceil(float(rank) / n);
		int prevrow = (rank % n == 0 ? n : rank % n);
		int row = (n + 1 - prevrow);
		printf("%d %d", col, row);
	}
	
	return 0;
}
