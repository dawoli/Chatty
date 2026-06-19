#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in", "r", stdin); freopen("seat.out", "w", stdout);
	int n, m, r, a[105], ind;
	cin >> n >> m >> r;
	a[1] = r;
	for (int i = 2; i <= n * m; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n * m, cmp);
	for (int i = 1; i <= n * m; i++){
		if (a[i] == r){
			ind = i;
		}
	}
	int x, y;
	x = (ind - 1) / n + 1;
	if (x % 2 == 1){
		y = (ind) % n + 1;
	}
	else{
		y = n - ((ind) % n);
	}
	cout << x << ' ' << y + 1;
}
