#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int c[n] = {0};
	for (int i=0; i<n; i++) {
		cin >> c[i];
	}
	sort(c, c+n);
	int prev = 0;
	int flag = 0;
	long long sum = 1;
	for (int i=0; i<n; i++) {
		if (flag==0 || prev==c[i]) {
			flag = 1;
			prev++;
		} else if (c[i+1] != prev){
			sum = sum * prev;
			prev = 0;
			flag = 0;
		}
	}
	cout << sum%998244353 << endl;
	return 0;
}
