#include <iostream>
#include <algorithm>
using namespace std;

int a[5005];
long long f[5005][5005][3];
const int mod = 998244353;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, maxa = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], maxa = max(maxa, a[i]);
	sort(a+1, a+n+1);
	for (int i = 0; i < n; i++)
		f[i][0][0] = 1;
	for (int i = 1; i < n; i++)
		for (int j = 0; j <= maxa + 1; j++){
			f[i][j][1] = (f[i-1][j][1] + f[i-1][max(0, j-a[i])][0]) % mod;
			f[i][j][2] = (f[i-1][j][2] + f[i-1][max(0, j-a[i])][1] + f[i-1][max(0, j-a[i])][2]) % mod;
		}
	long long ans = 0;
	for (int i = 3; i <= n; i++)
		ans = (ans + f[i-1][a[i]+1][2]) % mod;
	cout << ans << '\n';
	return 0;
}
