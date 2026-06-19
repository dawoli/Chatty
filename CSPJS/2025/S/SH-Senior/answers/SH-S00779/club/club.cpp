#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int x, y, z;
}a[100010];
int n, ans, t, sy, sz;
int dfs1(int pos, int sum, int ca, int cb, int cc){
	if (pos > n){
		return sum;
	}
	if (ca > n / 2 || cb > n / 2 || cc > n / 2) return 0;
	int xx, yy, zz;
	xx = dfs1(pos + 1, sum + a[pos + 1].x, ca + 1, cb, cc);
	yy = dfs1(pos + 1, sum + a[pos + 1].y, ca, cb + 1, cc);
	zz = dfs1(pos + 1, sum + a[pos + 1].z, ca, cb, cc + 1);
	return max(max(xx, yy), zz);
}
int dfs2(int pos, int sum, int ca, int cb){
	if (pos > n){
		return sum;
	}
	if (ca > n / 2 || cb > n / 2) return 0;
	int xx, yy;
	xx = dfs2(pos + 1, sum + a[pos + 1].x, ca + 1, cb);
	yy = dfs2(pos + 1, sum + a[pos + 1].y, ca, cb + 1);
	return max(xx, yy);
}
bool cmp(node x, node y){
	return x.x > y.x;
}
int main(){
	freopen("club3.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--){
		sy = sz = ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i].x >> a[i].y >> a[i].z, sy += a[i].y, sz += a[i].z;
		;
		if (sy == 0 && sz == 0){
			sort(a + 1, a + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++)
				ans += a[i].x;
		}
		else if (sz == 0) ans = dfs2(0, 0, 0, 0);
		else ans = dfs1(0, 0, 0, 0, 0);
		cout << ans << endl;
		for (int i = 1; i <= n; i++)
			a[i].x = a[i].y = a[i].z = 0; 
	}
	return 0;
}

