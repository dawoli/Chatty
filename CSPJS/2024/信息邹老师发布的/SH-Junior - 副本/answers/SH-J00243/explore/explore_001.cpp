#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e3+1;
char map[maxn][maxn];
int t,n,m,k,x0,y0,d0,cnt;
bool vis[maxn][maxn];
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--) {
		cnt=0;
		memset(vis,0,sizeof vis);
		cin>>n>>m>>k>>x0>>y0>>d0;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				cin>>map[i][j];
			}
		}
		vis[x0][y0]=1;
		while(k--) {
			if(d0==0&&y0<m&&map[x0][y0+1]=='.') {
				y0++;
				vis[x0][y0]=1;
			}
			else if(d0==1&&x0<n&&map[x0+1][y0]=='.') {
				x0++;
				vis[x0][y0]=1;
			}
			else if(d0==2&&y0>1&&map[x0][y0-1]=='.') {
				y0--;
				vis[x0][y0]=1;
			}
			else if(d0==3&&x0>1&&map[x0-1][y0]=='.') {
				x0--;
				vis[x0][y0]=1;
			}
			else {
				d0++;
				d0%=4;
			}
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(vis[i][j]) {
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
