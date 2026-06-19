#include <iostream>
using namespace std;
int main() {
	int t, num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	cin >> t;
	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n % 7 == 0) {
			n /= 7;
			for (int j = 0; j < n; j++) {
				cout << 8;
			}
			cout << endl;
		} else {
			cout << 10;
			n /= 7;
			n--;
			for (int j = 0; j < n; j++) {
				cout << 8;
			}
			cout << endl;
		}
	}
	return 0;
}
