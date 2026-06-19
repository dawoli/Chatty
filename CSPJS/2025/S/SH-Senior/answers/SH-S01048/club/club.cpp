#include <bits/stdc++.h>
using namespace std;

struct club{
	int c1;
	int c2;
	int c3;
//	int visited;
};

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		club a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i].c1 >> a[i].c2 >> a[i].c3;
		}
		int sum = 0;
		int flag[3] = {0};
		for (int i=0; i<n; i++) {
			if (a[i].c1>a[i].c2 && a[i].c1>a[i].c3) {
				if (flag[0] != n/2) {
					flag[0]++;
					sum += a[i].c1;
				}
			} else if (a[i].c2>a[i].c1 && a[i].c2>a[i].c3) {
				if (flag[1] != n/2) {
					flag[1]++;
					sum += a[i].c2;
				}
			} else {
				if (flag[2] != n/2) {
					flag[2]++;
					sum += a[i].c3;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
} 
