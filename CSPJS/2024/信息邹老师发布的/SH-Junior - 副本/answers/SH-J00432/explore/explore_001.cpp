#include <bits/stdc++.h>
using namespace std;

const int maxn=1010,maxm=1010;
int t,n,m,k,x,y,d,xp,yp;
char a[maxn][maxm];
bool done[maxn][maxm];

/*void debug() {
	for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				cout <<a[i][j];
			}
			cout <<endl;
		}
}*/
void toward() {
	xp=x; yp=y;
	if (d==0) yp=y+1;
	else if (d==1) xp=x+1;
	else if (d==2) yp=y-1;
	else if (d==3) xp=x-1;
	//printf("debug: (%d,%d)=>(%d,%d)\n",x,y,xp,yp);
}
int main() {
	//ios::sync_with_stdio(false);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >>t;
	while (t--) {
		memset(a,0,sizeof(a)); memset(done,0,sizeof(done));
		int x0,y0,d0; string s;
		cin >>n>>m>>k>>x0>>y0>>d0;
		x=x0;y=y0;d=d0; done[x0][y0]=1;
		for (int i=1;i<=n;i++) {
			cin >>s;
			for (int j=1;j<=m;j++) {
				a[i][j]=s[j-1];
			}
		}
		for (int i=1;i<=k;i++) {
			toward();
			if (xp>=1&&xp<=n&&yp>=1&&yp<=m&&a[xp][yp]=='.') {
				x=xp;y=yp; done[x][y]=1;
			} else {
				d=(d+1)%4;
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (done[i][j])
					ans++;
		cout <<ans<<endl;
	}
	return 0;
}
