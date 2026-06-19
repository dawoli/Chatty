#include <bits/stdc++.h>
using namespace std;
int t, n, m, vis[1010][1010], ans;
char a[1010][1010];
const int fx[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct Node{
	int x;
	int y;
	int step;
	int bomb;
}q[1000010];

void BFS(){
	int head = 1, tail = 2;
	q[1].x = 1;
	q[1].y = 1;
	q[1].step = 0;
	q[1].bomb = 1;
	while (head < tail){
		int x = q[head].x;
		int y = q[head].y;
		if (x == n && y == m){
			cout<<q[head].step<<endl;
		}
		int c = q[head].step;
		int d = q[head].bomb;
		for (int i = 0; i < 4; i++){
			int xx = x + fx[i][0];
			int yy = y + fx[i][1];
//			cout<<xx<<' '<<y<<endl;
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && vis[xx][yy] == 0 && a[xx][yy] != '*'){
				q[tail].x = xx;
//				cout<<xx<<' '<<yy<<endl;
//				cout<<"Ok"<<endl;
				q[tail].y = yy;
				q[tail].step = c + 1;
//				cout<<a[xx][yy]<<endl;
				if (a[xx][yy] == '$'){
					q[tail].bomb = d + 1;
					cout<<"OK"<<endl;
					cout<<q[tail].bomb<<endl;
				}
				vis[xx][yy] = 1;
				tail++;
			}
		}
		head++;
	}
}

int main(){
	freopen("bomb.in", "r", stdin);
	freopen("bomb.out", "w", stdout);
	cin>>t;
	for (int i = 1; i <= t; i++){
		memset(vis, 0, sizeof(vis));
		memset(q, 0, sizeof(q));
		cin>>n>>m;
		for (int j = 1; j <= n; j++){
			for (int k = 1; k <= m; k++){
				cin>>a[i][j];
				if (a[i][j] == '$'){
					ans++;
				}
			}
		}
		cout<<ans<<' ';
		BFS();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
1 30
........$..$...$..............
2 5
.*...
.$$$.
*/
