#include <bits/stdc++.h>
using namespace std;
int n , m , k , c[15] , a[15][10005] , f[10005];
long long ans;
struct node {
	int u , v , w;
}e[2000005];
int read () {
	int x = 0 , f = 1;
	char s = getchar ();
	while(s < '0' || s > '9') {
		if (s == '-') f = -1;
		s = getchar ();
	}
	while (s >= '0' && s <= '9') {
		x = x * 10 + s - '0';
		s = getchar ();
	}
	x *= f;
	return x;
}
bool cmp (node x , node y) {
	return x.w < y.w;
}
int find (int x) {
	if (f[x] == x) return x;
	return f[x] = find (f[x]);
}
int main () {
	freopen ("road.in" , "r" , stdin);
	freopen ("road.out" , "w" , stdout);
	n = read () , m = read () , k = read ();
	for (int i = 1; i <= m; i++) {
		e[i].u = read () , e[i].v = read () , e[i].w = read ();
	}
	if (k == 0) {
		sort (e + 1 , e + m + 1 , cmp);
		int num = 0;
		for (int i = 1; i <= n; i++) {
			f[i] = i;
		}
		for (int i = 1; i <= m; i++) {
			if (find (e[i].u) == find (e[i].v)) continue;
			ans += e[i].w;
			f[find (e[i].u)] = find (e[i].v);
			num++;
			if (num == n - 1) {
				cout << ans;
				return 0; 
			}
		}
	} else {
		int cnt = m;
		for (int i = 1; i <= k; i++) {
			c[i] = read ();
			int id = 0;
			for (int j = 1; j <= n; j++) {
				a[i][j] = read ();
				if (a[i][j] == 0) id = j;
			} 
			for (int j = 1; j <= n; j++) {
				if (j != id) {
					e[++cnt].u = j;
					e[cnt].v = id;
					e[cnt].w = a[i][j];
				}
			}	
		}
		sort (e + 1 , e + cnt + 1 , cmp);
		int num = 0;
		for (int i = 1; i <= n; i++) {
			f[i] = i;
		}
		for (int i = 1; i <= cnt; i++) {
			if (find (e[i].u) == find (e[i].v)) continue;
			ans += e[i].w;
			f[find (e[i].u)] = find (e[i].v);
			num++;
			if (num == n - 1) {
				cout << ans;
				return 0; 
			}
		}		
	}
	return 0;
}
