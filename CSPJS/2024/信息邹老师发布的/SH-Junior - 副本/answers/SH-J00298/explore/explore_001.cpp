#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,cnt = 0 ;
char mp[1005][1005];
bool vis[1005][1005];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool judge(int x, int y) {
	if(x > n || x < 1 || y > m || y < 1) return false;
	if(mp[x][y] == 'x') return false;
	return true;
}
void move(){
	
	if(judge(x + dx[d],y + dy[d])){
		x += dx[d]; y += dy[d];
		if(vis[x][y] == false){
			vis[x][y] = true;
			cnt ++;
			//cout << x << " " << y << " " << d << endl; 
		} 
		return;
	} 
	else{
		d = (d + 1) % 4;
		return;}
}
int main(){
	//
	//
	//
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int q; cin >> q; 
	while(q --){
		cnt = 1;
		memset(vis,0,sizeof(vis));
		cin >> n >> m >> k >> x >> y >> d;
		vis[x][y] = 1;
		for(int i = 1; i <= n; ++ i){
			for(int j = 1; j <= m; ++ j) cin >> mp[i][j];
		}
		for(int i = 1; i <= k; ++ i) move();
		cout << cnt << endl;
	}
	return 0;
}
