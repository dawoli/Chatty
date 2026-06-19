#include <iostream>
#include <cstdio>
using namespace std;
int t, n, m, k;
int x0, y0, d0;
char a[1005][1005];
int vst[1005][1005];
int dx[5] = {0, 1, 0, -1}, dy[5] = {1, 0, -1, 0};
//其中d = 0 代表向东，d = 1 代表向南，d = 2 代表向西，d = 3 代表向北
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while(t--){
		for(int i = 0; i <= n + 1; i++){
			for(int j = 0; j <= m + 1; j++){
				a[i][j] = '\0';
				vst[i][j] = 0;
			}
		}
		
		cin >> n >> m >> k;
		cin >> x0 >> y0 >> d0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> a[i][j];
			}
		}
		
		vst[x0][y0] = 1;
		for(int i = 1; i <= k; i++){
			if(a[dx[d0] + x0][dy[d0] + y0] == '.'){
				x0 = x0 + dx[d0];
				y0 = y0 + dy[d0];
				vst[x0][y0] = 1;
			}else{
				d0 = (d0 + 1) % 4;
			}
			
//			printf("x0:%d, y0:%d, d0:%d, vst[x0][y0]:%d\n", x0, y0, d0, vst[x0][y0]);
		}
		
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(vst[i][j] == 1){
//					cout << i << ' ' << j << endl;
					++ans;
				}
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}
