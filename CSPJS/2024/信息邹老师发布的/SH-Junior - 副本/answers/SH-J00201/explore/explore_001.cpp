#include <iostream>
#include <cstdio>
using namespace std;

int T,n,m,k,x0,y0,d0,ans;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool vis[1024][1024];
char Map[1024][1024];

int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while (T-->0) {
    	for (int i=1;i<=1010;i++) {
    		for (int j=1;j<=1010;j++) {
    			vis[i][j]=0;
			}
		}
    	cin >> n >> m >> k >> x0 >> y0 >> d0;
    	for (int i=1;i<=n;i++) {
    		for (int j=1;j<=m;j++) {
    			cin >> Map[i][j];
			}
		}
    	ans=1;
    	vis[x0][y0]=1;
    	while (k-->0) {
    		int x1=x0+dx[d0],y1=y0+dy[d0];
    		if (x1<1||y1<1||x1>n||y1>m||Map[x1][y1]=='x') {
    			d0=(d0+1)%4;
			}else{
				x0=x1;
				y0=y1;
				if (vis[x0][y0]==0) {
					ans++;
					vis[x0][y0]=1;
				}
			}
		}
		cout << ans << endl;
	}
}
