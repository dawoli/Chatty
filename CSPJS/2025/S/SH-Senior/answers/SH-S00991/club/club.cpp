#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;
int n;
int a[maxn][5];
int sz[5];
priority_queue<int, vector<int>, greater<int> > p[5];
inline void solve(){
	int ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
			ans += a[i][1];
			sz[1]++;
			if(a[i][2] < a[i][3]) p[1].push(a[i][1] - a[i][3]);
			else p[1].push(a[i][1] - a[i][2]);
		}else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]){
			ans += a[i][2];
			sz[2]++;
			if(a[i][3] < a[i][1]) p[2].push(a[i][2] - a[i][1]);
			else p[2].push(a[i][2] - a[i][3]);
		}else if(a[i][3] >= a[i][2] && a[i][3] >= a[i][1]){
			ans += a[i][3];
			sz[3]++;
			if(a[i][2] < a[i][1]) p[3].push(a[i][3] - a[i][1]);
			else p[3].push(a[i][3] - a[i][2]);
		}
	}
	
	int pur = 0;
	if(sz[1] > (n / 2)) pur = 1;
	else if(sz[2] > (n / 2)) pur = 2;
	else if(sz[3] > (n / 2)) pur = 3;
	
//	printf("pur:%d\n", pur); 
	
	if(pur == 0) ;
	else{
		while(sz[pur] > (n / 2)){
			int u = p[pur].top();
			p[pur].pop();
			sz[pur]--;
			ans -= u;
//			printf("u:%d\n", u);
		}
		
//		printf("OK\n");
	}
	
	cout << ans << '\n';
	while(!p[1].empty()) p[1].pop();
	while(!p[2].empty()) p[2].pop();
	while(!p[3].empty()) p[3].pop();
	
	sz[1] = sz[2] = sz[3] = 0;
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) solve();
	
	return 0;
}
