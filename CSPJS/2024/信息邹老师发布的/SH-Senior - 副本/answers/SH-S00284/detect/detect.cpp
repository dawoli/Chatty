#include<bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 1e5 + 9;

int T, n, m, l, v, p[maxn];

struct Node{
	int d, v, a;
}car[maxn];

signed main(){
	
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> n >> m >> l >> v;
		for(int j = 1; j <= n; j++){
			cin >> car[i].d >> car[i].v >> car[i].a;
		}
		for(int j = 1; j <= m; j++){
			cin >> p[i];
		}
	} 
	
	
	
	return 0;
}
