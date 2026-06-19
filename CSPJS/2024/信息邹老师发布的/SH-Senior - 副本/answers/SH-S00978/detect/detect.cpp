#include<bits/stdc++.h>
using namespace std;

struct car{
	int d;
	int v;
	int a;
};

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		int n, m, L, V;
		cin >> n >> m >> L >> V;
		car cars[n];
		for (int i=0; i<n; i++) {
			cin >> cars[i].d >> cars[i].v >> cars[i].a;
		}
		int p[m];
		for (int i=0; i<m; i++) {
			cin >> p[i];
		}
		int sum = 0;
		for (int i=0; i<n; i++) {
			if (cars[i].v > V) {
				sum++;
			}
		}
		cout << sum << " " << m-1 << endl;
	}
	return 0;
}
