#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int T, n, m, k, x0, yy, d0;
char mp[N][N];

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n >> m >> k;
		cin >> x0 >> yy >> d0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> mp[i][j]; 
			}
		}
		if(k == 1){
			if(d0 == 0){
				if(mp[x0][yy + 1] <= n && mp[x0][yy + 1] == '.') cout << 2 << endl;
				else cout << 1 << endl;
			}
			if(d0 == 1){
				if(mp[x0 + 1][yy] <= n && mp[x0 + 1][yy] == '.') cout << 2 << endl;
				else cout << 1 << endl;
			}
			if(d0 == 2){
				if(mp[x0][yy - 1] <= n && mp[x0][yy - 1] == '.') cout << 2 << endl;
				else cout << 1 << endl;
			}
			if(d0 == 3){
				if(mp[x0 - 1][yy] <= n && mp[x0 - 1][yy] == '.') cout << 2 << endl;
				else cout << 1 << endl;
			}
		}
	}
	return 0;
}
