#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z;
int xx[4]= {0,1,0,-1};
int yy[4]= {1,0,-1,0};
char ma[10005][10006];
bool maa[10005][10005];
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	while(T--) {
		int ans=0;
		cin >> n >> m>>k>>x>>y>>z;
		getchar();
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m+1; j++) {
				ma[i][j]=getchar();
				maa[i][j]=0;
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
			//	cout << ma[i][j]<<' ';
			}
			//cout << endl;
		}
		maa[x][y]=1;
		for(int i=1; i<=k; i++) {
			//cout << "ma[x+xx[z]][y+yy[z]]="<<ma[x+xx[z]][y+yy[z]]<<endl;
			if(1<=x+xx[z]&&x+xx[z]<=n&&1<=y+yy[z]&&y+yy[z]<=m&&ma[x+xx[z]][y+yy[z]]=='.') {
				y=y+yy[z];
				x=x+xx[z];
				maa[x][y]=1;
				//cout << "move:x="<<x<<", y="<<y<<","<<endl;
			} else {
				z=(z+1)%4;
				//cout << "z:z="<<z<<endl;
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(maa[i][j]) {
					ans++;
				}
			}
		}
		cout << ans<<endl;
	}
}//
