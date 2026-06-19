#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],sub;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> m >> n;
	for(int i=1;i<=n*m;++i) cin >> a[i];
	sub = a[1];
	sort(a+1,a+n*m+1);
	int p = 1,q = 1;
	for(int i=n*m;i;) {
		if(a[i] == sub) {
			cout << p << " " << q << endl;
			return 0;
		}
		--i;
		if(p%2 == 1 && q == m) ++p;
		else if(p%2 == 0 && q == 1) ++p;
		else if(p%2) ++q;
		else --q;
	}
}
/*
100  97
[99] 98
*/
