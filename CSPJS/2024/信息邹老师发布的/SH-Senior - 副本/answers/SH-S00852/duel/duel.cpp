#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int r[N];
int n;
int bl[N], sz[N], cnt;
int rem;

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	cin >> n;
	rem = n;
	for (int i = 1; i <= n; i ++ ) cin >> r[i];
	sort(r + 1, r + 1 + n);
	for (int i = 1; i <= n; i ++ )
	    if (r[i] == r[i - 1]) bl[cnt] ++ , sz[cnt] ++ ;
		else cnt ++ , bl[cnt] = sz[cnt] = 1;
		
	int l = 1, r = 2;
	while (r <= cnt)
	{
		int now = bl[r];
		while (r <= cnt && now < sz[l]) r ++ , now += bl[r];
		if(r > cnt) {rem -= now; break;}
		rem -= sz[l];
		bl[r] = now - sz[l];
		l ++ ;
		if (l == r) r ++ ;
	}	 
	
	cout << rem;
	return 0;
}
