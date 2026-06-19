#include <bits/stdc++.h>
using namespace std;

bool visited[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		memset(visited,false,sizeof(visited));
		int n, m, k;
		cin >> n >> m >> k;
		int x0, y0, d0;
		cin >> x0 >> y0 >> d0;
		
		char grid[n+1][m+1];
		for (int p=1;p<=n;p++) {
			for (int q=1;q<=m;q++){
				cin>>grid[p][q];
			}
		}
		
		int x=x0;
		int y=y0;
		int d=d0;
		visited[x][y]=true;
		int count=1;
		for (int a=0;a<k;a++){
			int tx=x+dx[d];
			int ty=y+dy[d];
			
			if (tx>=1&&tx<=n&&ty>=1&&ty<=m) {
				if (grid[tx][ty]=='.'){
					x=tx;
					y=ty;
				}
				else if (grid[tx][ty]=='x'){
					d=(d+1)%4;
				}
			}
			else{
				d=(d+1)%4;
			}
			
			//cout<<x<<' '<<y<<endl;
			
			if(visited[x][y]==false){
				count++;
				//cout<<"plus"<<endl;
			}
			visited[x][y]=true;
		}
		
		cout<<count<<endl;
		
		/*cout<<endl;
		for (int p=1;p<=n;p++) {
			for (int q=1;q<=m;q++){
				cout<<visited[p][q];
			}
			cout<<endl;
		}
		cout<<endl;
		for (int p=1;p<=n;p++) {
			for (int q=1;q<=m;q++){
				cout<<grid[p][q];
			}
			cout<<endl;
		}*/
	}
	return 0;
}
