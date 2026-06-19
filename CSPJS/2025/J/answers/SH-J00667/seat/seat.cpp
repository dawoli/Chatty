#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z, ans, a[105];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++) cin >> a[i];
	x = a[1];
	sort(a + 1, a + m * n + 1, cmp);
	for(int i = 1; i <= n * m; i ++)
		if(a[i] == x) y = i;
	z = ceil(1.0 * y / m);
	ans = y - (z - 1) * m;
	if(z % 2) cout << z << " " << ans;
	else cout << z << " " << m - ans + 1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
