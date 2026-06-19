#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int x, y, d, n, m, k, T, v[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
long long ans;
char a[1001][1001];
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		ans = 1;
		memset(v, 0, sizeof(v));
		scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d);
		for(int i=1; i<=n; i++){
			scanf("%s", a[i]+1);
		}
		v[x][y] = 1;
		for(int i=1; i<=k; i++){
			int x0 = x+dx[d], y0 = y+dy[d];
			if(x0 <= 0 || y0 <= 0 || x0 > n || y0 > m || a[x0][y0] == 'x'){
				d = (d+1)%4;
			}else if(x0 > 0 && y0 > 0 && x0 <= n && y0 <= m && a[x0][y0] == '.'){
				x = x0, y = y0;
				if(!v[x0][y0]) v[x0][y0] = 1, ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
