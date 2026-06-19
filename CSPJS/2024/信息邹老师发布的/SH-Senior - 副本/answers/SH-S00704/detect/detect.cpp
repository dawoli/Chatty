#include <bits/stdc++.h>
using namespace std;

int q;
int n,m,l,v;
int mc[100005];
struct node {
	int d,v,a;
	double li,ri;
}car[100005];

bool cmp(node x,node y) {
	if(x.li != y.li) return x.li < y.li;
	else return x.ri < y.ri;
}

bool chk(double l1,double r1) {
	int L = 0,r = m;
	while(L <= r) {
		int mid = (L + r) / 2;
		if(l1 > 1.0 * mc[mid]) {
			L = mid + 1;
		}
		else if(1.0 * mc[mid] > r1) {
			r = mid - 1;
		}
		else return true;
	}
	return false;
}

int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&q);
	while(q--) {
		scanf("%d%d%d%d",&n,&m,&l,&v);
		for(int i = 1; i <= n; i++) {
			scanf("%d%d%d",&car[i].d,&car[i].v,&car[i].a);
			if(car[i].a > 0) {
				double le = max(1.0 * (v * v - car[i].v * car[i].v) / (2 * car[i].a),0.0) + 1.0 * car[i].d + 0.01;
				if(le > l) {
					car[i].li = -1.0;
					car[i].ri = -1.0;
				}
				else {
					car[i].li = le;
					car[i].ri = 1.0 * l+0.01;
				}
			}
			else if(car[i].a == 0) {
				if(car[i].v > v) {
					car[i].li = 1.0 * car[i].d;
					car[i].ri = 1.0 * l + 0.01;
				}
				else {
					car[i].li = -1.0;
					car[i].ri = -1.0;
				}
			}
			else if(car[i].a < 0) {
				if(car[i].v <= v) {
					car[i].li = -1.0;
					car[i].ri = -1.0;
				}
				else {
					double le = 1.0 * (v * v - car[i].v * car[i].v) / (2 * car[i].a);
					if(le < 0) le = 0;
					le += 1.0 * car[i].d - 0.01;
					car[i].li = 1.0 * car[i].d;
					car[i].ri = min(le,1.0 * l); 
				}
			}
		}
		for(int i = 1; i <= m; i++) {
			scanf("%d",&mc[i]);
		}
		sort(car+1,car+n+1,cmp);
		sort(mc+1,mc+m+1);
		int ans1 = 0;
		for(int i = 1; i <= n; i++) {
			if(car[i].li == -1.0) continue;
			if(car[i].li <= mc[m]) ans1++;
			else {
				car[i].li = -1.0;
				car[i].ri = -1.0;
			}
		}
		cout << ans1 << " " << m - 1 << ' ' << endl;
	}
	return 0; 
}
