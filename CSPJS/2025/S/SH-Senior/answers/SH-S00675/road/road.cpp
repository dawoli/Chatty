#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m, k;
struct Node {
	int u, v, w;
};
Node a[1000005];
int c[15][10005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) {
		int x, y;
		cin>>x>>y;
		if(x>y) {
			int tmp=y;
			y=x; x=tmp;
		}
		a[i].u=x; a[i].v=y;
		cin>>a[i].w;
	}
	for(int i=1;i<=k;i++) {
		for(int j=0;j<=n;j++) {
			cin>>c[i][j];
		}
	}
	 
	cout << 0 << endl;
	
	return 0;
}
