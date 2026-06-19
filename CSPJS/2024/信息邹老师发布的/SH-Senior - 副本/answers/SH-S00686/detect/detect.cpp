#include<bits/stdc++.h>
using namespace std;

int T;
int n , m , L , VMAX;
int d[110000] , v[110000] , a[110000];
int p[110000];
 
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> T;
	while(T--) {
		int ans1 = 0 , ans2 = 0;
		int cnt = 0;
		memset(d , 0 , sizeof(d));
		memset(v , 0 , sizeof(v));
		memset(a , 0 , sizeof(a));
		memset(p , 0 , sizeof(p));
		cin >> n >> m >> L >> VMAX;
		for(int i = 1; i <= n; i++) {
			cin >> d[i] >> v[i] >> a[i];
		}
		for(int i = 1; i <= m; i++) {
			cin >> p[i];
			cnt++; 
		}
		sort(p+1 , p+1+m);	
		//≥ı ºªØ 
		
		bool flag = 1;
		for(int i = 1; i <= n; i++) {
			if(a[i] != 0){
				flag = 0;
				break;
			}
		}
		
		for(int i = 1; i <= n; i++) {
			if(flag == 1) {
				if(v[i] > VMAX) {
					if(d[i] <= p[cnt]) {
						ans1++;
						ans2 = 1;
					}
				}
			}
		}
		cout << ans1 << ' ' << m - ans2;
		cout << endl;
	}
	
	return 0;
}
