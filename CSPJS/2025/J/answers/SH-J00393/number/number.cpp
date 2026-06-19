#include <iostream>
#include <cstdio>

using namespace std;

int cnt[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	string a;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9')
			cnt[a[i] - '0']++;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= cnt[i]; j++)
			cout << i; 
	}
	cout << "\n";
	return 0;
}
