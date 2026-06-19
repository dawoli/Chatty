#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
char c[N][N];
struct P{int x,y;}que[N*N];
const int dx[] = {0,-1,0,1},dy[] = {1,0,-1,0};
int n,m,k;
bool vis[N][N];
void bfs(int x,int y,int d){
	int ff = 0,rr = 0,ti = 0;
	que[rr++] = {x,y};
	vis[x][y] = true;
	while(ff < rr){
		P u = que[ff++];
		for (int i = 0; i < 4; i++){
			int xx = u.x + dx[d],yy = u.y + dy[d];
			if (xx < 1 || xx > n || yy < 1 || yy > m || c[xx][yy] == 'x' || vis[xx][yy]) {d = (d + 1) % 4;ti++;continue;}
			que[rr++] = {xx,yy};
			vis[xx][yy] = true;
			ti++;
			break;
		}
		if (ti >= k) {cout << rr << endl;return;}
	}
	cout << rr << endl;
	return ;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m >> k;
		int x,y,d;
		cin >> x >> y >> d;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> c[i][j];
		memset(vis,0,sizeof vis);
		bfs(x,y,d);
	} 
	return 0;
}
