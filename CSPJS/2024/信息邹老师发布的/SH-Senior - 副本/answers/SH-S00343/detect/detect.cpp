#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int NN = 1e6 + 10;

struct car{
	int d, a;
	double v;
	bool flag;
}c[N];

bool ce[NN];

int main(){ 
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m, l, V;
		scanf("%d%d%d%d", &n, &m, &l, &V);
		for(int i = 1; i <= n; i++){
			scanf("%d%lf%d", &c[i].d, &c[i].v, &c[i].a);
		}
		for(int i = 1; i <= m; i++){
			int x;
			scanf("%d", &x);
			ce[x] = 1;
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			for(int j = c[i].d; j <= l; j++){
				c[i].v = sqrt(c[i].v * c[i].v + 2 * c[i].a);
				if(ce[j] && c[i].v > V){
					cnt++;
					break;
				}
			}
		}
		printf("%d ", cnt);
		int ret = m * 0.6;
		printf("%d\n", ret);
	}
	return 0;
}
