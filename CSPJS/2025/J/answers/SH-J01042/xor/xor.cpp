#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int a[n] = {0};
	int visited[n] = {0};
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int tmp = 0, flag = 0, sum = 0;
	int start = 0;
	for (int i=0; i<n; i++) {
		if (a[i] == k) {
			sum++;
			visited[i] = 1;
			tmp = 0;
			flag = 0;
		} else {
			if (flag == 0) {
				tmp = a[i];
				start = i;
				flag = 1;
			} else {
				tmp ^= a[i];
				if (tmp == k) {
					sum++;
					for (int j=start; j<=i; j++) {
						visited[j] = 1;
					}
					start = 0;
					flag = 0;
					tmp = 0;
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}
