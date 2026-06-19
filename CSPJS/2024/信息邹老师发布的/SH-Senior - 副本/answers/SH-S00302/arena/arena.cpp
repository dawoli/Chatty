#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
	int f = 1, x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return f * x;
}

const int maxn = 2e5 + 10;
int t, n, m, a[maxn], c[maxn];


signed main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> c[i];
	int a = 1;
	while(a < n){
		int x;
		cin >> x;
		a << 1;
	}
	cin >> t;
	cout << 1;
	return 0;
}
