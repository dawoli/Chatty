#include <bits/stdc++.h>
using namespace std;
int t , n , m , l , V , d[100005] , v[100005] , a[100005] , p[100005] , ans; 
void read (int &x) {
    int f = 1;
    x = 0;
    char s = getchar ();
    while (s < '0' || s > '9') {
        if (s == '-') f = -1;
        s = getchar ();
    }
    while (s >= '0' && s <= '9') {
        x = x * 10 + s - '0';
        s = getchar ();
    }
    x *= f;
}
int main () {
	freopen ("detect.in" , "r" , stdin);
	freopen ("detect.out" , "w" , stdout);
	read (t);
	while (t--) {
		read (n) , read (m) , read (l) , read (V);
		for (int i = 1; i <= n; i++) {
			read (d[i]) , read (v[i]) , read (a[i]);
		}
		for (int i = 1; i <= m; i++) {
			read (p[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				if (d[i] <= p[m] && v[i] > V) ans++;
			} else if (a[i] > 0) {
				if (d[i] > p[m]) continue;
				if (v[i] * v[i] + (2 * a[i] * (p[m] - d[i])) > V * V) ans++;
			}
		}
		cout << ans << " ";
		if (ans == 0) cout << m << "\n";
		else cout << m - 1 << "\n";
		ans = 0;
	}
    return 0;
}
