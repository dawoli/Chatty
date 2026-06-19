#include <iostream>
#include <cstdio>
using namespace std;

int T;
int n;
int a[200005];
int c[200005];

int calc() {
	int ret = 0;
	for (int i = 0; i < (1 << n); i++) {
		int cnt = 0, last_red = 0, last_blue = 0;
		for (int j = 1; j <= n; j++) {
			if ((i >> (j - 1)) & 1) {
				cnt += (last_red == a[j] ? a[j] : 0);
				last_red = a[j];
			}
			else {
				cnt += (last_blue == a[j] ? a[j] : 0);
				last_blue = a[j];
			}
		}
		ret = max(ret, cnt);
	}
	return ret;
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	cin >> T;
	
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		
		cout << calc() << endl;
	}
	
	return 0;
}
