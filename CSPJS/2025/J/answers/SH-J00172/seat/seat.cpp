#include <bits/stdc++.h>
using namespace std;

struct dat{int id,sc;};
const int N = 105;
dat a[N];
int n, m, p, q, wz;

bool cmp(dat x, dat y)
{
	return x.sc > y.sc;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++)
	{
		cin >> a[i].sc;
		a[i].id = i;
	}
	sort (a+1, a+n*m+1, cmp);
	for (int i = 1; i <= n*m; i++)
	{
		if (a[i].id == 1)
		{
			wz = i;
			break;
		}
	}
	p = wz / n;
	q = wz % n;
	if (q > 0) p++;
	else q = n;
	cout << p << " ";
	if (p % 2 != 0) cout << q << endl;
	else cout << n-q+1 << endl;
	return 0;
}
