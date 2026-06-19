#include <stdio.h>
#include <cstring>
int a;
short map[100005][1005];
int n, m, k;
int x, y, d;
int cnt;
char in[1005];
void turn() {
	d = (d + 1) % 4;
	k--;
}
void move(int d) {
	k--;
	map[x][y] = 2;
	if(d == 0) {
		y++;
		if(map[x][y] == 1) y--;
		if(map[x][y] != 2) cnt++;
		return;
	}
	if(d == 1) {
		x++;
		if(map[x][y] == 1) x--;
		if(map[x][y] != 2) cnt++;
		return;
	}
	if(d == 2) {
		y--;
		if(map[x][y] == 1) y++;
		if(map[x][y] != 2) cnt++;
		return;
	}
	if(d == 3) {
		x--;
		if(map[x][y] == 1) x++;
		if(map[x][y] != 2) cnt++;
		return;
	}
}
int main() {
	FILE* fp = fopen("explore.out", "r"); 
	FILE* fp2 = fopen("explore.out", "w"); 
	fscanf(fp, "%d", &a);
	for(int t = 0; t < a; ++t) {
		fscanf(fp, "%d%d%d", &n, &m, &k);
		fscanf(fp, "%d%d%d", &x, &y, &d);
		for(int i = 1; i <= n; ++i) {
			fscanf(fp, "%s", in);
			for(int j = 1; j <= m; ++j) {
				if(in[j] == (char)'x') 
				{
					map[i][j] = 1;
				}
			}
		}
		map[x][y] = 2;
		while(k >= 0) {
			//fprintf(fp2, ":%d, %d, %d, %d, %d\n", x, y, d, k, cnt);
			if(d == 0) {
				if((y + 1) > m || map[x][y + 1] == 1) turn();
				else move(d);
				//fprintf(fp2, ":%d, %d, %d, %d, %d\n", x, y, d, k, cnt);
			} else if(d == 1) {
				if((x + 1) > n || map[x + 1][y] == 1) turn();
				else move(d);
				//fprintf(fp2, ":%d, %d, %d, %d, %d\n", x, y, d, k, cnt);
			} else if(d == 2) {
				if((y - 1) <= 0 || map[x][y - 1] == 1) turn();
				else move(d);
				//fprintf(fp2, ":%d, %d, %d, %d, %d\n", x, y, d, k, cnt);
			} else if(d == 3) {
				if((x - 1) <= 0 || map[x - 1][y] == 1) turn();
				else move(d);
				//fprintf(fp2, ":%d, %d, %d, %d, %d\n", x, y, d, k, cnt);
			}
		}
		fprintf(fp2, "%d\n", cnt+1);
		cnt = 0;
		memset(map, 0, sizeof(map));
	}
	return 0;
}
