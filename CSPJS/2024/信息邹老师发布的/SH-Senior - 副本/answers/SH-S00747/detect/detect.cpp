#include<bits/stdc++.h> //40分 
using namespace std;
const int N = 1e5+10;
int T;
int n, m, l, V;
int d[N], v[N], a[N];
int p[N];
int main () {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> T;
	while(T--) {
		cin >> n >> m >> l >> V;
		bool st1 = true;
		for(int i = 1; i <= n; i ++) {
			cin >> d[i] >> v[i] >> a[i];
			if(a[i] != 0) st1 = false;
		}
		int lastdt = 0;
		for(int i = 1; i <= m; i ++) {
			cin >> p[i];
			lastdt = max(lastdt, p[i]);
		}
		//sort(p+1, p+1+n);
		//int lastdt = p[m];
		if(st1 == true) {
			int ans = 0;
			for(int i = 1; i <= n; i ++) {
				if(v[i] > V && d[i] <= lastdt) ans ++; 
			}
			if(ans == 0) {
				cout << ans << ' ' << m << endl;
			}
			else {
				cout << ans << ' ' << m-1 << endl;
			}
		}
		else {
			int ans = 0;
			for(int i = 1; i <= n; i ++) {
				if(v[i] > V && d[i] <= lastdt){
					ans ++;
				} 
				else if(d[i] > lastdt) {
					
				}
				else {
					double x = (V*V*1.000 - v[i]*v[i]*1.000)*1.000/(2.000*a[i]);
					//int x1 = x;
					double y = d[i]*1.000+x; //开始超速的地点
					double z = lastdt*1.000;
					int tt = ceil(y);
					if(tt == y) {
						tt+=1;
					}
					if(tt <= lastdt) ans ++;
				}
			}
			if(ans == 0) {
				cout << ans << ' ' << m << endl;
			}
			else {
				cout << ans << ' ' << m-1 << endl;
			}
		}
	}
	
	
	return 0;
}
/*
1
5 5 15 3
0 3 1
12 4 2
1 1 4
5 5 2
6 4 4
2 5 8 9 15
*/
