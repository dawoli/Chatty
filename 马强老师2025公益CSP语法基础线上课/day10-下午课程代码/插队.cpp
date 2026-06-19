#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int s;
	cin >> s;
	int a[55], x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[n + 1] = s;
	for (int i = 1; i <= n + 1; i++) {
		x = a[i];
		int j;
		for (j = i - 1; j >= 1; j--) {
			if (a[j] > x) {
				a[j + 1] = a[j];
			} else {
				break;
			}
		}
		a[j + 1] = x;
	}
	for (int i = 1; i <= n + 1; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
