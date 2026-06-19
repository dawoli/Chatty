#include<bits/stdc++.h>
using namespace std;

/*
拿40 AB 
*/

const int maxl = 100001;

int t;
int n, m, L, V, d[maxl], v[maxl], a[maxl], p[maxl];
int cnt;
double s; 

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
//	ios::sync_with_stdio(0);
	
	cin >> t;
	while (t--) {
		scanf("%d %d %d %d", &n, &m, &L, &V); 
		for (int i=0; i<n; i++) {
			scanf("%d %d %d", &d[i], &v[i], &a[i]); 
		}
		for (int i=1; i<=m; i++) scanf("%d", &p[i]);
		cnt=0;
		//开到哪会被抓？ 
		for (int i=0; i<n; i++) {
			if (a[i]==0) {
				if (v[i]>V && d[i] <= p[m]) cnt++;
				continue;
			}
			s = d[i] + max(0.0, (V*V-v[i]*v[i])/(2.0*a[i]));
			if (s < p[m]) cnt++;
//			else if (t==8) {
//				printf("<%d %d %d %d %d %d %d>", L, V, p[m], d[i], v[i], a[i], s);
//			}
		}
		
		printf("%d %d\n", cnt, m-(cnt!=0));
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

