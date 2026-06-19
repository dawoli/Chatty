#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1001;
int arr[maxn] = {0};

bool compare (int a, int b) {
	return a > b;
}

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n * m; i++) {
		cin >> arr[i];
	}
	
	int scoreR = arr[1];
	sort (arr + 1, arr + n * m + 1, compare);
	
	int index = -1;
	
	for (int i = 1; i <= n * m; i++) {
		if (arr[i] == scoreR) {
			index = i;
			break;
		}
	}
	
	if (((index - 1) / n) % 2 == 1) {
		cout << (index - 1) / n + 1 << ' ' << n - (index - 1) % n;
	} else {
		cout << (index - 1) / n + 1 << ' ' << (index - 1) % n + 1;
	}
	
	return 0;
}
