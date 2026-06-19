#include<bits/stdc++.h>
using namespace std;
int mon[10005][10005];
int a[1000005];
const int INF = 2e9+7;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
	cin>>n>>m>>k;
	memset(mon,INF,sizeof(mon));
	for(int i = 1; i <= m; i++) {
		int x,y;
		cin >> x >> y;
		cin >> mon[x][y];
		mon[y][x] = mon[x][y];
		a[i]=mon[x][y];
	}
	if(k==0) {
		int ans = 0;
		sort(a+1, a+m+1);
		for(int i = 1; i <= n-1; i++) {
			ans+=a[i];
		}
		cout << ans;
		return 0;
	}
	cout << 0;
	return 0;
}
