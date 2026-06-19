//26/10/24 16:04
#include<bits/stdc++.h>
using namespace std;

int T, n, m, L, V, d[100005], v[100005], a[100005], p[100005];
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	while(T --){
		int mx = 0;
		cin >> n >> m >> L >> V;
		bool flag = true;
		for(int i = 1; i <= n; ++ i){
			cin >> d[i] >> v[i] >> a[i];
			if(a[i])
				flag = false;
		}
		for(int i = 1; i <= m; ++ i){
			cin >> p[i];
			mx = max(mx, p[i]);
		}
		
		if(flag){
			int cnt = 0;
			for(int i = 1; i <= n; ++ i)
				cnt += (v[i] > V && d[i] <= mx);
			cout << cnt << ' ' << m - 1 << endl;
		}
		cout << n << ' ' << m - 1 << endl;
	}
	return 0;
}
