#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
const double eps = 1e-6;
double d[N],v[N],a[N];
double dv_l[N],dv_r[N];
int t,n,m,all;
double L,V;
double p[N];
bool pp[N];
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lf%lf",&n,&m,&L,&V);
		for(int i = 1; i <= n; i++){
			scanf("%lf%lf%lf",&d[i],&v[i],&a[i]);
			if(a[i] == 0){
				if(v[i] > V){
					dv_l[i] = d[i];
					dv_r[i] = L;
				}else if(v[i] <= V){
					dv_l[i] = L + eps;
					dv_r[i] = -eps;
				}
			}else if(a[i] > 0){
				dv_l[i] = d[i] + (V + v[i]) * (V - v[i]) / 2.0 / a[i] + eps;
				dv_r[i] = L;
			}else if(a[i] < 0){
				dv_l[i] = d[i];
				dv_r[i] = d[i] + (V + v[i]) * (V - v[i]) / 2.0 / a[i] - eps;
				if(dv_r[i] < dv_l[i]){
					dv_l[i] = L + eps;
					dv_r[i] = -eps;
				}
			}
			dv_l[i] = max(dv_l[i],d[i] - eps);
			dv_l[i] = min(dv_l[i],L + eps);
			dv_r[i] = max(dv_r[i],d[i] - eps);
			dv_r[i] = min(dv_r[i],L + eps);
		}
		for(int i = 1; i <= m; i++){
			scanf("%lf",&p[i]);
		}
		all = 0; 
		for(int i = 1; i <= n; i++){
			int kk = lower_bound(p + 1,p + m + 1,dv_l[i]) - p;
			if(dv_l[i] <= p[kk]&&p[kk] <= dv_r[i]){
				all++;
				pp[kk] = true;
			}
		}
		int sum = 0;
		for(int i = 1; i <= m; i++){
			if(!pp[i]){
				sum++;
			}
		}
		printf("%lld %lld\n",all,sum);
	}
    return 0;
}
/*
2 
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
*/
