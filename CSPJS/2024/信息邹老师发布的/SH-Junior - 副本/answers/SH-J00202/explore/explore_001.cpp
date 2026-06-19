#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,x,y,z,rx[4] = {0,1,0,-1},ry[4] = {1,0,-1,0};char c[1010][1010];bool vst[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(int o = 1;o <= t;o++){
		cin >> n >> m >> k;
		cin >> x >> y >> z; 
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cin >> c[i][j];
				vst[i][j] = 0;
			}
		}
		vst[x][y] = 1;
		int cnt = 1;
		for(int i = 1;i <= k;i++){
			int gx = x + rx[z],gy = y + ry[z];
			if(gx && gx <= n && gy && gy <= m && c[gx][gy] == '.') x = gx,y = gy;
			else z = (z + 1) % 4;
			if(!vst[x][y]) vst[x][y] = 1,cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
