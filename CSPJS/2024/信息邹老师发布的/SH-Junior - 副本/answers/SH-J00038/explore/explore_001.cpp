#include<bits/stdc++.h>
using namespace std;
int cnt;
char mp[1005][1005];
bool vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n,m,k,x0,y0,d0;
		cin >> n >> m >> k >> x0 >> y0 >> d0;
		cnt = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cin >> mp[i][j];
				vis[i][j] = 0;
			}
		}
		vis[x0][y0] = 1;
		while(k--){
			if(d0 == 0){
				y0++;
				if(x0 < 1 || x0 > n || y0 < 1 || y0 > m || mp[x0][y0] == 'x'){
					y0--;
					d0++;
					d0 %= 4;
				}
			}else if(d0 == 1){
				x0++;
				if(x0 < 1 || x0 > n || y0 < 1 || y0 > m || mp[x0][y0] == 'x'){
					x0--;
					d0++;
					d0 %= 4;
				}
			}else if(d0 == 2){
				y0--;
				if(x0 < 1 || x0 > n || y0 < 1 || y0 > m || mp[x0][y0] == 'x'){
					y0++;
					d0++;
					d0 %= 4;
				}
			}else if(d0 == 3){
				x0--;
				if(x0 < 1 || x0 > n || y0 < 1 || y0 > m || mp[x0][y0] == 'x'){
					x0++;
					d0++;
					d0 %= 4;
				}
			}
			vis[x0][y0] = 1;
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(vis[i][j]) cnt++;
			}
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
