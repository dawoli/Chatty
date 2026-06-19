#include <bits/stdc++.h>
using namespace std;
int n , a[100005] , attack[100005] , defend[100005] , b[100005] , tot , l = 1 , r = 2 , ans;
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
	freopen ("duel.in" , "r" , stdin);
	freopen ("duel.out" , "w" , stdout);
	read (n);
	for (int i = 1; i <= n; i++) {
		read (a[i]);
		attack[a[i]]++;
		defend[a[i]]++;
		if (attack[a[i]] == 1) b[++tot] = a[i];
	}
	sort (b + 1 , b + tot + 1);
	while (l < r && r <= tot) {
		if (attack[b[r]] >= defend[b[l]]) {
			attack[b[r]] -= defend[b[l]];
			ans += defend[b[l]];
			defend[b[l]] = 0;
			l++;
			if (l == r) r++;
		} else {
			defend[b[l]] -= attack[b[r]];
			ans += attack[b[r]];
			attack[b[r]] = 0;
			r++;
		}
	}
	cout << n - ans;
    return 0;
}
