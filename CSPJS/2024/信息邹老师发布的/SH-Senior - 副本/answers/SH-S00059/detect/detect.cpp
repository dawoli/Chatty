#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T, n, m, l, vroad;
int d[MAXN], v[MAXN], a[MAXN], p[MAXN];
int cntcar, cntmust, maxneed, minneed;
int max0; 
//maxneed后一定要有探头即可满足 a>= 0的情况 
int i, j;
double overt, overp; //overspeed time/point
vector<int> needl, needr;

int datatype = 2;

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	scanf("%d", &T);
	
	for (i = 0; i < T; i++) {
		//INPUT
		scanf("%d %d %d %d", &n, &m, &l, &vroad);
		//printf("%d %d %d %d\n", n, m, l, vroad);
		maxneed = -1;
		minneed = l+1;
		max0 = -1;
		cntmust = 0;
		cntcar = 0;
		//needl.clear();
		//needr.clear();
		//memset(d, sizeof(d), 0);
		//memset(v, sizeof(v), 0);
		//memset(a, sizeof(a), 0);
		//memset(p, sizeof(p), 0);
		for (j = 0; j < n; j++) {
			scanf("%d %d %d", d+j, v+j, a+j);
		}
		for (j = 0; j < m; j++) {
			scanf("%d", p+j);
		}
		
		if (a[0] == 0) datatype = 0;
		if (a[0] > 0) datatype = 1;
		
		//CALC
		for (j = 0; j < n; j++) {
			if (a[j] == 0) {
				if (v[j] > vroad) {
					if (p[m-1] >= d[j]) {
						cntcar++;
						max0 = max(max0, d[j]); 
						//printf("%d 0 indist=%d\n", j, d[j]);
					}
				}
			} else if (a[j] > 0) {
				overt = (double)(vroad - v[j]) / a[j];
				if (vroad < v[j]) {
					overp = d[j];
					if (p[m-1] >= d[j]) cntcar++;
				} else if (vroad == v[j]) {
					if (p[m-1] > d[j]) cntcar++;
				} else {
					overp = v[j] * 1.0 * overt + 0.5 * a[j] * overt * overt + d[j];
					overp += 1e-8;
					if (p[m-1] > (int)overp) cntcar++;
				}
				//maxneed = max(maxneed, int(overp));
				//printf("%d 1 vroad-vj=%d aj=%d indist=%d overt=%.2lf overp=%.2lf\n", j, vroad-v[j], a[j], d[j], overt, overp);
			} else if (a[j] < 0) {
				if (v[j] > vroad) {
					overt = (vroad - v[j]) * 1.0 / a[j]; //不再超速的时间
					overp = v[j] * 1.0 * overt + 0.5 * a[j] * overt * overt + d[j];
					for (int k = 0; k < m; k++) {
						if (p[k] >= d[j]) {
							if (- overp + p[k] <= 1e-8) {
								cntcar++; break;
							}
						}
					}
				}
				//printf("%d 1 vj-l=%d aj=%d indist=%d overt=%.2lf overp=%.2lf\n", j, v[j]-l, a[j], d[j], overt, overp);
			}
		}
		
		//OUTPUT
		for (j = 0; j < m; j++) {
			if (p[j] < max0) {
				cntmust++;
			}
		}
		if (cntcar == 0) {
			printf("%d %d\n", 0, m);
		} else {
			if (datatype == 0 || datatype == 1) {
				printf("%d %d\n", cntcar, m - 1);
			} else {
				printf("%d %d\n", cntcar, cntmust);
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
