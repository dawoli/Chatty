#include<iostream>
#include<queue>
using namespace std;
const int N = 1e3 + 10;
string mapp[N];
int n, m, v[N][N], d[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
struct node{
	int x;
	int y;
};
int bfs(int sx, int sy, int ccd, int k){
	int i, cd = ccd, count = 1, ck = k;
	queue<node> q;
	q.push({sx, sy});
	v[sx][sy] = 1;
	while(ck--){
		node head = q.front();
		int nx = head.x + d[cd][0];
		int ny = head.y + d[cd][1];
		//cout << nx << " " << ny << " " << cd << " " << endl;
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && mapp[nx][ny] == '.'){
			//cout << "go" << nx << " " << ny << endl << "k:" << ck << endl;
			q.pop();
			q.push({nx, ny});
			if(!v[nx][ny]) count += 1;
			v[nx][ny] = 1;
			//cout << count << endl;
		}
		else{
			cd = (cd + 1) % 4;
		}
   }
	return count;
}
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int i, j, t, k, sx, sy, ccd;
	cin >> t;
	while(t--){
	    cin >> n >> m >> k;
	    cin >> sx >> sy >> ccd;
		for(i = 0; i < n; i++){
			cin >> mapp[i];
	    }
	    for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			v[i][j] = 0;
	    }
	    }
	    cout << bfs(sx-1, sy-1, ccd, k) << endl;
	}
	fclose(stdin);
	fclose(stdout);
}

