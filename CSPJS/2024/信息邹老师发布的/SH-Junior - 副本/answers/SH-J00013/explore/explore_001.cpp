#include <bits/stdc++.h>
using namespace std;

char mp[1145][1145];
int t;
bool pm[1145][1145];
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int k, n, m;
	int ans = 0;
	int x, y, d;
	cin >> t;
	while(t--){
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> mp[i][j];
				pm[i][j] = false;
			}
		}
		ans++;
		pm[x][y] = true;
		for(int i = 1; i <= k; i++){
			if(x+dx[d] <= n && x + dx[d] >= 1 && y+dy[d] <= m && y+dy[d] >= 1){
				if(mp[x+dx[d]][y+dy[d]] == '.'){
					x += dx[d];
					y += dy[d];
					if(pm[x][y] == false){
						pm[x][y] = true;
						ans++;
					}
					continue;
				}
			}
			d = (d+1)%4;
		}
		cout << ans << endl;
	}
	return 0;
}
