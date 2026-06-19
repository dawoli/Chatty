#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 7;
int t, n, m, L, V;
int b[maxn][4], p[maxn];

int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin >> t;
	while(t--){
		cin >> n >> m >> L >> V;
		int ans1 = 0, ans2 = m;
		for(int i = 1, x, y, z; i <= n; ++ i){
			cin >> x >> y >> z;
			b[i][1] = x, b[i][2] = y, b[i][3] = z;
		}
		for(int i = 1,x; i <= m; ++ i)cin >> p[i];
		int biggg = p[m];
		for(int i = 1; i<= n; ++i ){
			int v = b[i][2], d = b[i][1];
			if(v>V&&d<=p[m])ans1++;
		}
		
		if(ans1)ans2--;
		cout << ans1 << ' ' << ans2;
		if(t) cout << '\n';
	}
	
	return 0;
}
