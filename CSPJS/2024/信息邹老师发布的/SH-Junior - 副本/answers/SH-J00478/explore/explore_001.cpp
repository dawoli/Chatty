#include <bits/stdc++.h>
using namespace std;

int T;
string hang;
int n, m, k;
int ans;
int sx, sy, di;
char matrix[1005][1005];
int mark[1005][1005];
int dire[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool is_out(int nx, int ny, int d, int xx, int yy){
	//cout<<matrix[nx+dire[d][0]][ny+dire[d][1]];
	return (matrix[nx+dire[d][0]][ny+dire[d][1]]=='.' and nx+dire[d][0]>0 and nx+dire[d][0]<xx + 1 and ny+dire[d][1]>0 and ny+dire[d][1]<yy + 1);
}


int main( ){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin>>T;
	for (int i = 0; i < T; i++){
		cin>>n>>m>>k;
		cin>>sx>>sy>>di;
		for (int j = 1; j <= n; j++){
			cin>>hang;
			for (int q = 1; q <= m; q++){
				matrix[j][q] = hang[q - 1];
			}
		}
		ans = 1;
		mark[sx][sy] = 1;
		for (int u = 0; u < k; u++){
			if (!is_out(sx, sy, di, n, m)){
				di += 1;
				di = di % 4;
				continue;
			}
			if (is_out(sx, sy, di, n, m)){
				sx += dire[di][0];
				sy += dire[di][1];
				if (mark[sx][sy] != 1){
					mark[sx][sy] = 1;
					ans++;
				}
			}
		}
		cout<<ans;
		if (i != T-1){
			cout<<"\n";
		}
		for (int p = 1; p <= n; p++){
			for (int o = 1; o <= m; o++){
				mark[p][o] = 0;
			}
		}
	}
	
	return 0;
	
}
