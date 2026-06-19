#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x = 0,f = 1; char c = getchar();
	while('0' > c || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while('0' <= c && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	} return x * f;
}
const int maxn = 400010;
const int inf = 1e9;
const double eps = 1e-9;
inline double mf(double a,double b){return (a > b + eps) ? b : a;}
inline double mx(double a,double b){return (a > b + eps) ? a : b;}
typedef struct{int d,v,a;double pos;}crr;
typedef struct{double l,r;} inv;
int n,m,L,V,ans;
crr cr[maxn]; inv iv[maxn];
double posi[maxn];
bool operator <(inv a,inv b){
	return (fabs(a.r - b.r) < eps) ? a.l < b.l : a.r < b.r;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T = read();
	while(T--){
		n = read(),m = read(),L = read(),V = read(); 
		ans = 0;vector<int> vc; int cnt = 0,f = 1,g = 1;
		for(int i = 1 ; i <= n ; i ++) cr[i].d = read(),cr[i].v = read(),cr[i].a = read();
		posi[1] = -1; posi[m+2] = 1e9;
		for(int i = 1 ; i <= n ; i ++) {
			if(cr[i].a != 0) f = -1;
			if(cr[i].a <= 0) g = -1;
		}
		for(int i = 1 ; i <= m ; i ++) scanf("%lf",&posi[i+1]);
		m += 2;
		sort(posi + 1,posi + m + 1);
		if(f == 1){
			for(int i = 1 ; i <= n ; i ++) if(cr[i].v > V && cr[i].d <= posi[m-1]) cnt += 1;
			printf("%d %d\n",cnt,m - 3);
			continue;
		}else if(g == 1){
			for(int i = 1 ; i <= n ; i ++){
				long double d = cr[i].d,v = cr[i].v,a = cr[i].a;
				if(a > 0){
					long double s = posi[m-1] - d;
					long double vv = sqrt(v * v + 2 * a * s);
					if(vv > V + eps) cnt += 1;
				}
			}
			printf("%d %d\n",cnt,m - 3);
			continue;
		}
		for(int i = 1 ; i <= n ; i ++){
			double d = cr[i].d,v = cr[i].v,a = cr[i].a;
			if(a > 0){
				double t = (V - v) * 1.0 / (a * 1.0);
				if(d + 0.5 * a * t * t + 1.0 * v * t > L + eps) cr[i].pos = 1e9;
				else cr[i].pos = d + 0.5 * a * t * t + v * t;
			}else if(a < 0){
				double t = (V - v) * 1.0 / (a * 1.0);
				if(v < V) cr[i].pos = 1e9;
				else cr[i].pos = mf(1.0 * d + 0.5 * a * t * t + 1.0 * v * t,1.0 * L) - eps; 
			}else if(a == 0) cr[i].pos = 0;
		}
		for(int i = 1 ; i <= n ; i ++){
			if(cr[i].a > 0 && cr[i].pos != 1e9){
				double l = cr[i].pos,r = L * 1.0;
				if(fabs(l - posi[m-1]) < eps) continue;
				if(posi[m-1] > l + eps) vc.push_back(i),iv[++cnt] = {l,r+eps};
			}else if(cr[i].a == 0){
				if(cr[i].v <= V) continue;
				int p = upper_bound(posi + 1,posi + m + 1,cr[i].d + eps) - posi;
				if(p <= m) vc.push_back(i),iv[++cnt] = {cr[i].d * 1.0 + eps,L * 1.0 - eps};
			}else if(cr[i].a < 0 && cr[i].pos != 1e9){
				double l = cr[i].d,r = cr[i].pos;
				int p1 = upper_bound(posi + 1,posi + m + 1,l + eps) - posi;
				if(posi[p1] <= r + eps) vc.push_back(i),iv[++cnt] = {l,r+eps};
			}
		}
		printf("%d ",cnt);
		sort(iv + 1,iv + cnt + 1);
		double crt = -1;
		for(int i = 1 ; i <= cnt ; i ++){
			if(iv[i].l <= crt && iv[i].r >= crt) continue;
			ans += 1;
			int u = upper_bound(posi + 1,posi + m + 1,iv[i].r) - posi - 1;
			crt = mx(crt,posi[u]);
		}
		printf("%d\n",m - 2 - ans);
	}	
	return 0;
} 
