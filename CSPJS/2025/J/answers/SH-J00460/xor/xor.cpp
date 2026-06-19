#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5 * 1e5 + 5;
ll n , k , cnt , xx , d;
ll a[N] , q[N] , vis[N];
struct s
{
	ll x , y , dis;
}b[N];
bool check(int dd)
{
	for (int i = b[dd].x ; i <= b[dd].y ; i ++)
	{
		if (vis[i] == 1)
		{
			return false;
		}
	}
	for (int i = b[dd].x ; i <= b[dd].y ; i ++)
	{
		vis[i] = 1;
	}
	return true;
}
bool cmp(s aa , s bb)
{
	return aa.dis < bb.dis;
}
int main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i];
		q[i] = q[i - 1] ^ a[i];
	}
	for (int i = 1 ; i <= n ; i ++)
	{
		xx = 0;
		for (int j = i ; j <= n ; j ++)
		{
			xx ^= a[j];
			if (xx == k)
			{
				d ++;
				b[d].x = i;
				b[d].y = j;
				b[d].dis = j - i + 1;
				break;
			}
		}
	}
	sort(b + 1 , b + d + 1 , cmp);
	for (int i = 1 ; i <= d ; i ++)
	{
		if (check(i))
		{
			cnt ++;
		}
	}
	cout << cnt;
	return 0;
}
