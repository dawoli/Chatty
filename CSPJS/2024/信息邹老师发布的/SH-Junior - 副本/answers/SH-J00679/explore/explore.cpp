#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d;
char a[1010][100010];
bool b[1010][100010];
bool check() {
	int xx=x,yy=y;
	if(d == 0) yy +=1;
	if(d == 1) xx +=1;
	if(d == 2) yy -=1;
	if(d == 3) xx -=1;
	if((xx >= 1 && xx <= n)&&(yy >= 1 && yy <= m)&&(a[xx][yy]=='.')) {
		return true;
	} else {
		return false;
	}
}
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	for(int q = 1; q <= T; q++) {
		cin >> n >> m >> k >> x >> y >> d;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> a[i][j];
				b[i][j] = false;
			}
		}
		b[x][y]=true;
		for(int i = 1; i <= k; i++) {
			if(check()) {
				if(d == 0) y += 1;
				if(d == 1) x += 1;
				if(d == 2) y -= 1;
				if(d == 3) x -= 1;
				b[x][y] = true;
			} else {
				d = (d+1) % 4;
			}
		}
		int ans=0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(b[i][j] == true)	ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
