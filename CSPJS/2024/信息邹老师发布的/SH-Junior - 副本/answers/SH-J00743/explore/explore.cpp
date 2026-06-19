#include <bits/stdc++.h>
using namespace std;
//#define DBG
char explore[2000][2000];
bool passed[2000][2000];
int T,n,m,k,x,y,d, nextX, nextY;

void solve(){
	--x, --y;
	passed[x][y] = 1;
	while (k--){
		if (d == 0)
			nextX = x, nextY = y+1;
		if (d == 1)
			nextX = x+1, nextY = y;
		if (d == 2)
			nextX = x, nextY = y-1;
		if (d == 3)
			nextX = x-1, nextY = y;
		if (explore[nextX][nextY] == '.'){
			passed[nextX][nextY] = 1, x = nextX, y = nextY;
			#ifdef DBG
			printf("Next Stop: (%d,%d) with .\n", x, y);
			#endif
		}else{
			d = (d+1)%4;
			#ifdef DBG
			printf("Crash and d turns into %d\n", d);
			#endif
		}
	}
	int cont = 0; 
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j)
			#ifndef DBG
			if (passed[i][j]) ++cont;
			#else
			printf("%d ", passed[i][j]);
			#endif
		#ifdef DBG
		printf("\n");
		#endif
	}
	#ifndef DBG
	printf("%d\n", cont);
	#else
	printf("------\n");
	#endif
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			passed[i][j] = 0;
		}
	}
}

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	scanf("%d", &T);
	while (T--){
		scanf("%d %d %d", &n, &m, &k);
		scanf("%d %d %d", &x, &y, &d);
		for (int i = 0; i < n; ++i){
			scanf("%s", &explore[i]);
		}
		solve();
	}
	return 0;
}
