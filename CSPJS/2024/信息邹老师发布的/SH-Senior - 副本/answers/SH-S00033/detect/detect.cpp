#include<bits/stdc++.h>
using namespace std;
struct car{
	int d,v,a;
	double s;
}c[100005];
struct xian{
	int l,r;
} ti[100005];
bool p[1000005];
int wz[100005];
int pre[1000005];
int suf[1000005];
int imp[100005];
bool cam[100005];
bool cmp(xian x,xian y){
	return x.r < y.r;
}
int main(){
	freopen("detect2.in","r",stdin);
//	freopen("detect.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		memset(p,0,sizeof p);
		memset(imp,0,sizeof imp);
		memset(cam,0,sizeof cam);
		int n,m,L,V,cnt = 0,cnt2 = 0;
		cin >> n >> m >> L >> V;
		for(int i = 1;i <= n;i++){
			cin >> c[i].d >> c[i].v >> c[i].a;
			if(c[i].a > 0) c[i].s = c[i].d + (V * V - c[i].v * c[i].v) * 1.0 / c[i].a / 2;
			if(c[i].a < 0) c[i].s = c[i].d - (c[i].v * c[i].v) * 1.0 / c[i].a / 2;
		}
		for(int i = 1;i <= m;i++){
			int x;
			cin >> x;
			p[x] = 1;
			wz[i] = x;
		}
		pre[0] = 0;
		suf[L] = 0;
		for(int i = 1;i <= L;i++){
			pre[i] = pre[i - 1] + p[i];
		}
		for(int i = L;i >= 1;i--){
			suf[i] = suf[i + 1] + p[i];
		}
		for(int i = 1;i <= n;i++){
			cout << endl << i << ' ' << c[i].d << ' ';
			printf("%.12lf ",c[i].s);
			if(c[i].a == 0){
				if(c[i].v > V){
					cnt++;
				}
			}else if(c[i].a > 0){
				if(c[i].v > V){
					if(suf[c[i].d + 1]) cnt++;
					ti[i].l = c[i].d + 1;
					ti[i].r = L;
					continue;
				}
				if(c[i].s > L) continue;
				if(suf[int(ceil(c[i].s)) + 1]) cnt++;
				ti[i].l = ceil(c[i].s) + 1;
				ti[i].r = L;
			}else{
				if(c[i].s > L){
					if(suf[c[i].d + 1]) cnt++;
					ti[i].l = c[i].d + 1;
					ti[i].r = L;
					continue;
				}
				if(pre[int(floor(c[i].s)) - 1] - pre[c[i].d] > 0) cnt++;
				ti[i].l = c[i].d + 1;
				ti[i].r = floor(c[i].s)
			}
		}
		sort(ti + 1,ti + n + 1,cmp);
		int tmp = 0;
		int j = 1;
		while(tmp <= n){
			for(int k = 1;k <= m;k++){
				wz[k]
			}
		} 
		cout << cnt << ' ' << cnt2 << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
}
