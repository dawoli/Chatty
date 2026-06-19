#include <bits/stdc++.h>
using namespace std;

//d的定义 0:x,y+1; 1:x+1,y; 2:x,y-1; 3:x-1,y
//向右转: (d+1)%4 

struct pos {
	int x,y;
}po[1000005];

bool che(int i,int j,int a) {
	for (int x=1;x<=a;x++) {
		if (po[x].x == i && po[x].y == j) {
			return 0;
		} 
	}
	return 1;
} 

int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	for (int A=1;A<=T;A++) {
		int n,m,k;
		cin >> n >> m >> k; 
		int x,y,d,K=k;
		cin >> x >> y >> d;
		x--;
		y--; 
		char mp[1005][1005]; 
		for (int i=0;i<n;i++) {
			cin >> mp[i];
		}
		int ans=1;
		for (;k>0;k--) {
			if (d == 0) {
				if (y+1>m-1 || mp[x][y+1] == 'x') {
					d = (d+1)%4;
				} else {
					y++;
					if (che(x,y,K-k)) {
					ans ++;
					po[K-k+1].x = x;
					po[K-k+1].y = y;
				}
				}
			} else if (d == 1) {
				if (x+1>n-1 || mp[x+1][y] == 'x') {
					d = (d+1)%4;
				} else {
					x++;
					if (che(x,y,K-k)) {
					ans ++;
					po[K-k+1].x = x;
					po[K-k+1].y = y;
				}
				}
			} else if (d == 2) {
				if (y-1<0 || mp[x][y-1] == 'x') {
					d = (d+1)%4;
				} else {
					y--;
					if (che(x,y,K-k)) {
					ans ++;
					po[K-k+1].x = x;
					po[K-k+1].y = y;
				}
				}
			} else if (d == 3) {
				if (x-1<0 || mp[x-1][y] == 'x') {
					d = (d+1)%4;
				} else {
					x--;
					if (che(x,y,K-k)) {
					ans ++;
					po[K-k+1].x = x;
					po[K-k+1].y = y;
				}
				}
			}
		}
		cout << ans << endl;
	} 
	return 0;
} 
