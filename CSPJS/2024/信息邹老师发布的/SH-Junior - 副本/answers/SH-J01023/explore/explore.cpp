#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+5;
char mp[MAXN][MAXN];
int mpp[MAXN][MAXN];
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	int T;
	cin >> T;
	while(T--){
		memset(mpp, 0, sizeof(mpp));
		int n, m, k, x, y, d, ans = 1;
		cin >> n >> m >> k >> x >> y >> d;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				cin >> mp[i][j];
			}
		}
		while(k){
			int x0 = x, y0 = y;
			mpp[x][y] = 1;
			ans++;
			if(d == 0){
				y++;
			}else if(d == 1){
				x++;
			}else if(d == 2){
				y--;
			}else{
				x--;
			}
			if(mpp[x][y] == 1){
				ans--;
			}
			if(x<1 || x>n || y<1 || y>m || mp[x][y] == 'x'){
				x = x0, y = y0;
				ans--;
				d = (d+1)%4;
			}
			k--;
		}
	    cout << ans << '\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

