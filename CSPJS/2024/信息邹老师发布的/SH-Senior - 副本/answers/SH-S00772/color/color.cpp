#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int T, n, a[N], ans;
bool p[15];
void godo(){
	int tot = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i - 1; j >= 1; j--){
			if(p[i] == p[j] && a[i] == a[j])
				tot += a[i];
		}
	ans = max(ans, tot);
}
void dfs(int x){
	if(x == n + 1){
		godo();
		return;
	}
	p[x] = 0;
	dfs(x + 1);
	p[x] = 1;
	dfs(x + 1);
}
void solveBF(){
	dfs(1);
	printf("%d\n", ans);
}
int f[105][105][2], mx[105];
void solve(){
	for(int i = 1; i <= n; i++){
		f[1][i][0] = 0;
		f[1][i][1] = 0;
	}
	for(int i = 2; i <= n; i++){
		for(int j = 1; j < i; j++){
//			f[i][j][0] = max(f[i - 1][j][0],f[i][j - 1][1]);
//			f[i][j][1] = max(f[i - 1][j][1], f[i][j - 1][0]);
			f[i][j][0] = mx[i - 1];
			if(a[i] != a[j])
				continue;
			int mxr = 0, mxb = 0;
			for(int k = 1; k <= n; k++){
				mxr = max(mxr, f[j][k][0]);
				mxb = max(mxb, f[j][k][1]);
			}
			f[i][j][0] += mxr + a[i];
			f[i][j][1] += mxb + a[i];
			mx[i] = max(mx[i], f[i][j][0]);
			mx[i] = max(mx[i], f[i][j][1]);
//			cout << f[i][j][0] << " " << f[i][j][1] << endl;
		}
	}
	int ans = 0;
//	for(int i = 1; i <= n; i++, cout << endl)
//		for(int j = 1; j <= n; j++)
//			cout << f[i][j][0] << " ";
	for(int i = 1; i <= n; i++){
		ans = max(ans, f[n][i][0]);
		ans = max(ans, f[n][i][1]);
	}
	printf("%d\n", ans);
}
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &T);
	while(T > 0){
		T--;
		ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		if(n <= 10){
			solveBF();
		}
		else if(n <= 100){
			solve();
		}
	}
	return 0;
}

