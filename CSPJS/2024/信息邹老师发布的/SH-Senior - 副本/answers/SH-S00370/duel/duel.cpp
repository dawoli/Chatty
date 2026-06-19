#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int j = 1;
	for (int i = 2; i <= n; i++)
		if (a[j] < a[i])
			j++;
	cout << n - j + 1;
	return 0;
}

