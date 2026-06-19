#include <bits/stdc++.h>
using namespace std;
double d[100005];
double v[100005];
double a[100005];
double p[100005];
double sudden_v(double begin, double len, double faster){
	if (begin * begin + 2 * faster * len >= 0)
		return sqrt(begin * begin + 2 * faster * len);
	return 0;
}
struct overspeed{
	int bg, ed;
}os[100005];
bool cmp(overspeed x, overspeed y){
	if (x.ed != y.ed) return x.ed < y.ed;
	return x.bg < y.bg;
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int cur = 0;
		int n, m, L, V;
		cin >> n >> m >> L >> V;
		for (int i = 1; i <= n; i++){
			cin >> d[i] >> v[i] >> a[i];
		}
		for (int i = 1; i <= m; i++){
			cin >> p[i];
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			if (d[i] > p[m]) continue;
			int l = 1, r = m, nxt_detect;
			while(l <= r){
				int mid = (l + r) / 2;
				if (p[mid] >= d[i]){
					nxt_detect = mid;
					r = mid - 1;
				}else{
					l = mid + 1;
				}	
			}
			if (a[i] >= 0){
				//判断位于d[m]会不会超速 
				if (sudden_v(v[i], p[m] - d[i], a[i]) > V){
					cnt++; 
					//此时寻找最近的p[ans]使得p[ans]超速
					int L = nxt_detect, R = m, ans;
					while(L <= R){
						int mid = (L + R) / 2;
						if (sudden_v(v[i], p[mid] - d[i], a[i]) > V){
							ans = mid;
							R = mid - 1;
						}else{
							L = mid + 1;
						}
					}
					//第ans到m可检测出超速  
					os[++cur] = {ans,m};
				}
				 
				 
			}else{
				//判断位于距离现在最近的测速点会不会超速
				

				if (sudden_v(v[i], p[nxt_detect] - d[i], a[i]) > V){
					cnt++;
					//判断最远的超速点 
					int L = nxt_detect, R = m, ans;
					while(L <= R){
						int mid = (L + R) / 2;
						if (sudden_v(v[i], p[mid] - d[i], a[i]) > V){
							ans = mid;
							L = mid + 1;
						}else{
							R = mid - 1;
						}
					}
					os[++cur] ={nxt_detect,ans};
					//此时的ans就是最远的超速点 
					//第nxt_detect到ans可检测出超速 
				} 
				
				
				
			}
			
		}
		cout << cnt << " ";
		sort(os + 1, os + cur + 1, cmp);
		int now = os[1].ed, irre = 1; 
		for (int i = 2; i <= cur; i++){
//			cout << os[i].bg << " " << os[i].ed << endl;
			if(os[i].bg > now){
				irre++;
				now = os[i].ed;
			}
		}
		cout << m - irre << endl;
	} 
} 
