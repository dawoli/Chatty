#include <bits/stdc++.h>
using namespace std;
int t , n;
struct node {
	int yi , er , san , cha;
}a[100005];
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
	return x.cha > y.cha;
}
int main () {
	freopen ("club.in" , "r" , stdin);
	freopen ("club.out" , "w" , stdout);
	t = read ();
	while (t--) {
		n = read ();
		for (int i = 1; i <= n; i++) {
			a[i].yi = read () , a[i].er = read () , a[i].san = read ();
			if (a[i].yi >= a[i].er && a[i].yi >= a[i].san) {
				a[i].cha = a[i].yi - max (a[i].er , a[i].san);
			} else if (a[i].er >= a[i].yi && a[i].er >= a[i].san) {
				a[i].cha = a[i].er - max (a[i].yi , a[i].san); 
			} else {
				a[i].cha = a[i].san - max (a[i].yi , a[i].er);
			}
		}
		sort (a + 1 , a + n + 1 , cmp);
		int num1 = 0 , num2 = 0 , num3 = 0 , ans = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i].yi >= a[i].er && a[i].yi >= a[i].san) {
				if (num1 < n / 2) {
					num1++;
					ans += a[i].yi;
				} else {
					ans += max (a[i].er , a[i].san);
				}
			} else if (a[i].er >= a[i].yi && a[i].er >= a[i].san) {
				if (num2 < n / 2) {
					num2++;
					ans += a[i].er;
				} else {
					ans += max (a[i].yi , a[i].san);
				}
			} else {
				if (num3 < n / 2) {
					num3++;
					ans += a[i].san;
				} else {
					ans += max (a[i].yi , a[i].er);
				}
			}		
		}
		cout << ans << "\n";
	}
	return 0;
}
