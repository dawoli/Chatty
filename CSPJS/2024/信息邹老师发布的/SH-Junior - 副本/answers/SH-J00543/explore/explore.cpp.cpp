#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
ll n, m, k;
ll _x, _y, _d;
char c[1007][1007];
bool f[1007][1007] = {0};
void dfs(ll x, ll y, int dir, ll stp, ll cnt){
	if(stp == 0){
		cout << cnt << "\n";
		return ;
	}
	else if(dir == 0){
		if(x > n || x < 1 || y + 1 > m || y + 1 < 1 || c[x][y + 1] == 'x'){
			dir = (dir + 1) % 4;
			dfs(x, y, dir, stp - 1, cnt);
		}	
		else{
			y += 1;
			if(!f[x][y]){
				f[x][y] = 1;
				dfs(x, y, dir, stp - 1, cnt + 1);
			} 
			else 
				dfs(x, y, dir, stp - 1, cnt);
		}
	}
	else if(dir == 1){
		if(x + 1 > n || x + 1 < 1 || y > m || y < 1 || c[x + 1][y] == 'x'){
			dir = (dir + 1) % 4;
			dfs(x, y, dir, stp - 1, cnt);
		}	
		else{
			x += 1;
			if(!f[x][y]){
				f[x][y] = 1;
				dfs(x, y, dir, stp - 1, cnt + 1);
			} 
			else 
				dfs(x, y, dir, stp - 1, cnt);
		}
	}
	else if(dir == 2){
		if(x > n || x < 1 || y - 1 > m || y - 1 < 1 || c[x][y - 1] == 'x'){
			dir = (dir + 1) % 4;
			dfs(x, y, dir, stp - 1, cnt);
		}	
		else{
			y -= 1;
			if(!f[x][y]){
				f[x][y] = 1;
				dfs(x, y, dir, stp - 1, cnt + 1);
			} 
			else 
				dfs(x, y, dir, stp - 1, cnt);
		}
	}
	else if(dir == 3){
		if(x - 1 > n || x - 1 < 1 || y > m || y < 1 || c[x - 1][y] == 'x'){
			dir = (dir + 1) % 4;
			dfs(x, y, dir, stp - 1, cnt);
		}	
		else{
			x -= 1;
			if(!f[x][y]){
				f[x][y] = 1;
				dfs(x, y, dir, stp - 1, cnt + 1);
			} 
			else 
				dfs(x, y, dir, stp - 1, cnt);
		}
	}
}
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n >> m >> k;
		cin >> _x >> _y >> _d;
		for(ll i = 1; i <= n; ++i)
			for(ll j = 1; j <= m; ++j)
				cin >> c[i][j];
		f[_x][_y] = 1;
		dfs(_x, _y, _d, k, 1);
		memset(c, 0, sizeof c);
		memset(f, 0, sizeof f);		
	}
	return 0;
} 
