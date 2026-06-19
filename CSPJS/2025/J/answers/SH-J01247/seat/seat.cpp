#include <bits/stdc++.h>
using namespace std;

struct Node {
	int id,num;
}a[1005];

int n,m;

bool cmp(Node x, Node y) {
	return x.num > y.num;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <=n * m; i++) {
		cin >> a[i].num;
		a[i].id = i;
	}
	sort(a+1,a+n*m+1,cmp);
	int ans = 0;
	for (int i = 1; i <= n * m; i++) {
		if (a[i].id == 1) {
			ans = i;
			break;
		}
	}
	int sx,sy;
	sx = ans / n;
	sy = ans % n;
	if (sx == 0) {
		cout << 1 << " " << sy;
		return 0;
	}
	if (sx % 2 == 1) {
		if (sy == 0) {
			cout << sx << " " << n;
		}
		else {
			cout << sx+1 << " " << n - (sy - 1);
		} 
	}
	else {
		if (sy == 0) {
			cout << sx << " " << 1;
		}
		else {
			cout << sx+1 << " " << sy;
		}
	}
	return 0;
}
