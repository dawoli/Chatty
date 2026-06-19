#include <bits/stdc++.h>
using namespace std;
int b[105];
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m , ss = 0;
	cin >> n >> m;
	for(int i = 1; i <= n * m; ++i) cin >> b[i];
	b[0] = b[1];
	sort(b + 1 , b + (n*m) + 1 , greater<int>());
	for(int i = 1; i <= n * m; ++i)
		if(b[i] == b[0]) ss = i;
	int oo = ss / n;
	int pp = ss % n;
	if(oo % 2 == 0 and pp) cout << oo + 1 << " " << pp;
	else if(oo % 2 == 0 and !pp) cout << oo << " " << pp;
	else if(oo % 2 and pp)cout << oo + 1 << " " << n - pp + 1;
	else cout << oo << " " << n - pp;
	return 0;
}
