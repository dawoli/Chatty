#include<bits/stdc++.h>
#define ll long long
using namespace std;

//Ð¡ÐÄll 

const int N = 10001;
int SP1234=1, SP_A=1;
ll n, m, k, c[11], a[11][N];
ll wsum=0; 
vector<pair<int, ll> > g[N];

int main() {
	freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i=1; i<=n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
		wsum += w;
	}
	for (int i=1; i<=k; i++) {
		cin >> c[i];
		if (c[i]) SP_A = 0;
		int flag = 0;
		for (int j=1; j<=n; j++) {
			cin >> a[i][j];
			if (!flag&&!a[i][j]) flag=1;
		}
		if (!flag) SP_A = 0;
	}
	SP1234 = (!k);
	if (SP1234) {
		cout << wsum;
		return 0;
	}
	if (SP_A) {
		
//		return 0;
	}
	cout << wsum;
	 
	return 0;
}
