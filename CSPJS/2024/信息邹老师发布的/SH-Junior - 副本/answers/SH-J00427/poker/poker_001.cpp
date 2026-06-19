#include <stdio.h>
bool poker[15][5];
int n,cnt;
char a[5];
int main() {
	FILE* fp = fopen("poker.in", "r");
	FILE* fp2 = fopen("poker.out", "w");
	fscanf(fp, "%d", &n);
	for(int i = 0; i < n; ++i) {
		fscanf(fp, "%s", a);
		if(a[1] == (char)'A') {
			if(a[0] == (char)'D') poker[1][1] = 1;
			if(a[0] == (char)'C') poker[1][2] = 1;
			if(a[0] == (char)'H') poker[1][3] = 1;
			if(a[0] == (char)'S') poker[1][4] = 1;
		} else if(a[1]>='1' && a[1]<='9') {
			if(a[0] == (char)'D') poker[a[1] - 48][1] = 1;
			if(a[0] == (char)'C') poker[a[1] - 48][2] = 1;
			if(a[0] == (char)'H') poker[a[1] - 48][3] = 1;
			if(a[0] == (char)'S') poker[a[1] - 48][4] = 1;
		} else if(a[1] == (char)'T') {
			if(a[0] == (char)'D') poker[10][1] = 1;
			if(a[0] == (char)'C') poker[10][2] = 1;
			if(a[0] == (char)'H') poker[10][3] = 1;
			if(a[0] == (char)'S') poker[10][4] = 1;
		} else if(a[1] == (char)'J') {
			if(a[0] == (char)'D') poker[11][1] = 1;
			if(a[0] == (char)'C') poker[11][2] = 1;
			if(a[0] == (char)'H') poker[11][3] = 1;
			if(a[0] == (char)'S') poker[11][4] = 1;
		} else if(a[1] == (char)'Q') {
			if(a[0] == (char)'D') poker[12][1] = 1;
			if(a[0] == (char)'C') poker[12][2] = 1;
			if(a[0] == (char)'H') poker[12][3] = 1;
			if(a[0] == (char)'S') poker[12][4] = 1;
		} else if(a[1] == (char)'K') {
			if(a[0] == (char)'D') poker[13][1] = 1;
			if(a[0] == (char)'C') poker[13][2] = 1;
			if(a[0] == (char)'H') poker[13][3] = 1;
			if(a[0] == (char)'S') poker[13][4] = 1;
		}
	}
	for(int i = 1; i <= 13; ++i) {
		for(int j = 1; j <= 4; ++j) {
			if(!poker[i][j]) {
				cnt++;
			}
		}
	}
	fprintf(fp2, "%d\n", cnt);
	return 0;
}
