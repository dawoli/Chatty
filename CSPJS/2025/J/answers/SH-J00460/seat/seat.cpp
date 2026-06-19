#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
ll n , m , x , c , r , op;
ll a[N];
bool cmp(ll aa , ll bb)
{
	return aa > bb;
}
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n * m ; i ++)
	{
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1 , a + n * m + 1 , cmp);
	c = 1;
	r = 1;
	op = 1;
	for (int i = 1 ; i <= n * m ; i ++)
	{
		if (a[i] == x)
		{
			cout << c << " " << r;
			break;
		}
		if (op == 1)
		{
			if (r == n)
			{
				c ++;
				op = 2;
			}
			else
			{
				r ++;
			}
		}
		else
		{
			if (r == 1)
			{
				c ++;
				op = 1;
			}
			else
			{
				r --;
			}
		}
	}
	return 0;
}
