#include<iostream> 
using namespace std;
int T;
int n,m,k;
int x0,y0,d; 
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char MAP[1005][1005];
int vis[1005][1005];
int main() {
	freopen("explore.in",'r',"explore.in");
	freopen("explore.out",'w',"explore.out");
	cin>>T;
	while(T--) {
		cin >> n >> m >> k;
		cin >> x0 >> y0 >> d;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				cin >> MAP[i][j];
				vis[i][j] = 0;
			}
		}
		int ans = 1;
		vis[x0][y0] = 1;
		while(k > 0) {
			int fx = x0 + dx[d];
			int fy = y0 + dy[d];
			if(fx > 0 && fx <= n && fy > 0 && fy <= m && MAP[fx][fy] == '.') {
				x0 = fx;
				y0 = fy;
				if(vis[fx][fy] == 0) {
					ans++;
					vis[fx][fy] = 1;
				}
			}
			else {
				d = (d + 1) % 4;
			}
			k--;
		}
		cout << ans << endl;
	}
	return 0;
} 
