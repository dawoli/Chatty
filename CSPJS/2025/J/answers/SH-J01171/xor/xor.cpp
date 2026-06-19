#include <bits/stdc++.h>
using namespace std;

int n; long long k;
int a[500005];
long long pre[500005];
bool test_1 = true;
bool test_2 = true;
long long table[5005][5005];
int mx = INT_MIN;

void solveMain() {
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if (i == j) table[i][j] = a[i];
			else {
				table[i][j] = pre[j] ^ pre[i-1];
			}
		}
	}
	
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if (table[i][j] == k) {
				cnt++;
				i = j;
				break;
			}
		}
	}
	
	printf("%d", cnt);
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%d %lld", &n, &k);
	pre[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		pre[i] = pre[i-1] xor a[i];
		if (i > 1 && a[i] != a[i-1]) test_1 = false;
		if (a[i] != 0 && a[i] != 1) test_2 = false;
	}
	
	if (k == 0 && test_1) {
		printf("%d", n/2);
		return 0;
	}
	
	if (k <= 1 && test_2) {
		if (k == 0) {
			int cnt = 0;
			for (int i = 1; i <= n; ++i) {
				if (a[i] == 0) cnt++;
				else {
					if (a[i+1] == 1) {
						cnt++;
						i++;
					}
				}
			}
			
			printf("%d", cnt);
			return 0;
		}
		else if (k == 1) {
			int cnt = 0;
			for (int i = 1; i <= n; ++i) {
				if (a[i] == 1) cnt++;
			}
			
			printf("%d", cnt);
			return 0;
		}
	}
	
	solveMain();
	return 0;
}
