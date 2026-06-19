#include <bits/stdc++.h>
#define MAXN 2005
using namespace std;

int T, n;
int a[MAXN];
//char flag[MAXN]; //a:any; r:red; b:blue
int tt, i, j, ij;

int ans, thisans;

int lastred, lastblue;
int powv;

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	scanf("%d", &T);
	
	for (tt = 0; tt < T; tt++) {
		ans = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", a+i);
		}
		for (i = 0; i < (int)pow(2, n); i++) {
			thisans = 0; lastred = lastblue = -1; powv = 1;
			for (j = 0; j < n; j++) {
				ij = (i / powv) % 2; //0:blue 1:red
				powv *= 2;
				if (ij == 0) {
					if (lastblue != -1) {
					if (a[j] == a[lastblue]) {
						thisans += a[j];
					}
					}
					lastblue = j;
				} else {
					if (lastred != -1) {
					if (a[j] == a[lastred]) {
						thisans += a[j];
					}
					}
					lastred = j;
				}
			}
			if (thisans > ans) {
				ans = thisans;
			}
		}
		printf("%d\n", ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
