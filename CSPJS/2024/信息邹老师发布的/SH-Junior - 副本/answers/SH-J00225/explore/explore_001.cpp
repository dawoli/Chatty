#include<bits/stdc++.h>
using namespace std;

char a[1005][1005];
bool vis[1005][1005];
int nd[10][10] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main(){
 	freopen("explore.in", "r", stdin);
 	freopen("explore.out", "w", stdout);
	long long int k, n, T, m, x, y, d, ans;
	scanf("%lld", &T);
	while(T--){
		ans = 1;
		scanf("%lld %lld %lld", &n, &m, &k);
		scanf("%lld %lld %lld", &x, &y, &d);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cin >> a[i][j];
			}
		}
		vis[x][y] = 1;
		while(k--){
			int nx = x + nd[d][0];
			int ny = y + nd[d][1];
			if(nx >= 1 && nx <= n && ny >= 1 && nx <= m){
				if(a[nx][ny] == '.'){
					x = nx;
					y = ny;
					if(vis[x][y] == 0){
					    ans++;
					}
					vis[x][y] = 1;
					cout << nx << ' ' << ny << ' ' << ans <<'|';
				}else{
					d = (d + 1) % 4;
				}
			}else{
				d = (d + 1) % 4;
			}
		}
		printf("%lld\n", ans);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				vis[i][j] = 0; 
			}
		}
	}
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
}
