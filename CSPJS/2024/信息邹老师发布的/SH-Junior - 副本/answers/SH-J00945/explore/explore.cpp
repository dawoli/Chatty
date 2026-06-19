#include<bits/stdc++.h>
using namespace std;

int t, ans;
int n,m,k,x,y,d;
bool a[1005][1005];
bool b[1005][1005];
int f[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void way(){
	d = (d+1)%4;
}

int go(int x, int y, int la){
	int re = 1;
	while (la){
		int nx = x+f[d][0], ny = y+f[d][1];
		if (nx > 0 and nx <= n and ny > 0 and ny <= m and !a[nx][ny]) {
			if (!b[nx][ny])re++,b[nx][ny]=1;
			x=nx,y=ny;
		} else way();
		la--;
	}
	return re;
}

int main () {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m >> k >> x >> y >> d;
		ans = 1;
		for (int j = 1; j <= n; j++) {
			for (int p = 1; p <= m; p++) {
			char c;
			cin >> c;
			if (c=='.')a[j][p]=0;
			else a[j][p]=1;
			}
		}
		for (int j = 1; j <= n; j++) {
			for (int p = 1; p <= m; p++)b[j][p]=0;
		}
		b[x][y]=1;
		ans = go(x,y,k);
		cout << ans << endl;
	}
	return 0;
}
