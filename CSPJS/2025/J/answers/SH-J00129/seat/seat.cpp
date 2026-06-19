#include <iostream>
#include <algorithm>
using namespace std;

int a[105];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, p;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	p = a[1];
	sort(a+1, a+n*m+1, cmp);
	int x, y, f = 1;
	x = y = 1;
	for (int i = 1; i <= n * m; i++){
		if (a[i] == p){
			cout << x << ' ' << y << '\n';
		}
		if (y + f > n || y + f < 1){
			x++;
			f = -f;
		} else {
			y += f;
		}
	}
	return 0;
}
