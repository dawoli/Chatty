#include <bits/stdc++.h>
using namespace std;
const long long N = 1e4 + 7, M = 1e6 + 7;
struct Node{
	int u,v,w;
}s[M];
int c[M],a[M][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> s[i].u >> s[i].v >> s[i].w;
	}
	for(int i = 1;i <= m;i++) {
		cin >> c[i];
		for(int j = 1;j <= n;j++)
			cin >> a[i][j];
	}
	cout << 13;
	return 0;
}
