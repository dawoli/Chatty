// 特殊性质大法  
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct Node {
	int d, v, a;
}a[MAXN];
int p[MAXN];
int f[MAXN]; // 记录这辆车是否已经超速  
int T, n, m, L, V;
int ans1, ans2;
bool cmp1(Node x, Node y) {
	return x.d < y.d;
}
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> T;
	while(T--) {
		for(int i=1; i<=n; i++) {
			a[i].d=a[i].v=a[i].a=0;
		}
		ans1=0;
		ans2=0;
		n=0;
		m=0;
		L=0;
		V=0;
		memset(f, 0, sizeof(f));
		bool flagA=0, flagB=0;
		scanf("%d%d%d%d", &n, &m, &L, &V);
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d", &a[i].d, &a[i].v, &a[i].a);
			if(a[i].a<0) flagB=1;
		}
		for(int i=1; i<=m; i++) {
			scanf("%d", &p[i]);
		}
		sort(a+1, a+n+1, cmp1);
		// 满足特殊性质A、B的做法 ——  匀加速运动 且加速度 >=0 可得20分  
		if(!flagB) {
			int tm=0;
			for(int i=1; i<=m; i++) {
	//			cout << "i=" << i << ", p[i]=" <<p[i]<<endl;
				for(int j=1; j<=n; j++) {
					if(a[j].d>p[i]) {
						continue;
					} // 若这辆车还未驶入，则跳过 
					if(f[j]!=0) {
						f[j]=i;
						tm=max(tm, f[j]);
						continue;
					} // 若已经超速，则跳过  
					if(a[j].a==0) {
						if(a[j].v>V) {
							f[j]=i;
							ans1++;
							tm=max(tm, f[j]);
						}
					} 
					else if(sqrt(pow(a[j].v, 2)+2*a[j].a*(p[i]-a[j].d)) > (double)V) { // 超速判断  \sqrt{{v_0}^2+2as}
//						cout << sqrt(a[j].v*a[j].v+2*a[j].a*(a[j].d-p[i])) << endl;
						f[j]=i;
						ans1++;
						tm=max(tm, f[j]);
					}
				}
			}
			ans2=tm-1;
			if(ans1==0) { // 特判  
				ans2=m;
			}
			printf("%d %d\n", ans1, ans2);
		} else {
			int tm=0;
			for(int i=1; i<=m; i++) {
	//			cout << "i=" << i << ", p[i]=" <<p[i]<<endl;
				for(int j=1; j<=n; j++) {
					if(a[j].d>p[i]) {
						continue;
					} // 若这辆车还未驶入，则跳过 
					if(f[j]!=0) {
						f[j]=i;
						tm=max(tm, f[j]);
						continue;
					} // 若已经超速，则跳过  
					if(a[j].a==0) {
						if(a[j].v>V) {
							f[j]=i;
							ans1++;
							tm=max(tm, f[j]);
						}
					} 
					else if(sqrt(pow(a[j].v, 2)+2*a[j].a*(p[i]-a[j].d)) > (double)V) { // 超速判断  \sqrt{{v_0}^2+2as}
//						cout << sqrt(a[j].v*a[j].v+2*a[j].a*(a[j].d-p[i])) << endl;
						f[j]=i;
						ans1++;
						tm=max(tm, f[j]);
					}
				}
			}
			ans2=tm-1;ans2++;
			if(ans1==0) { // 特判  
				ans2=m;
			}
			printf("%d %d\n", ans1, ans2);
		}
	} 
	
	return 0;
}
