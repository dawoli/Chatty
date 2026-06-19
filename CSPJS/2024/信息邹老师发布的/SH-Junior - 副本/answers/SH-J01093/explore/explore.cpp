#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

char Map[N][N];

int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		int x,y,d;
		scanf("%d%d%d",&x,&y,&d);
		for(int i = 1;i <= n;i++) {
			scanf("%s",Map[i] + 1);
		}
		int cnt = 1;
		Map[x][y] = 'w';
		while(k--) {
			int ux = x,uy = y;
			if(d == 0) {
				uy++;
			}
			if(d == 1) {
				ux++;
			}
			if(d == 2) {
				uy--;
			}
			if(d == 3) {
				ux--;
			}
			if(ux >= 1 && ux <= n && uy >= 1 && uy <= m && Map[ux][uy] != 'x') {
				if(Map[ux][uy] != 'w') {
					cnt ++;
					Map[ux][uy] = 'w';
				}
				x = ux,y = uy;
			}
			else {
				d = (d + 1) % 4;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
