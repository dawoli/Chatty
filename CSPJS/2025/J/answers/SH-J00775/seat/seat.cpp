#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
struct s {
	int a, b; 
} c[110];

bool cmp(s a, s b) {
	return a.a > b.a;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> c[i].a;
		c[i].b = i;
	}
	sort(c + 1, c + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (c[i].b == 1) {
			int ansc = (i - 1) / n + 1, ansr = (i - 1) % n + 1;
			if (ansc % 2 == 0) {
				ansr = n - ansr + 1;
			}
			cout << ansc << " " << ansr;
			break;
		}
	}
	
	return 0;
}  
