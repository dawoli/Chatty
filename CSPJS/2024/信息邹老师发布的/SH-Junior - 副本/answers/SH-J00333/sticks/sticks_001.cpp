#include <cstdio>
using namespace std;

typedef unsigned long long ll;
const int N = 1e5;
int k, n, T, anss[52];
int sticks[10];
int check(int m)
{
	int used = 0;
	int x=m;
	while (x>0)
	{
		used += sticks[x%10];
		x /= 10;
	}
	return used;
}
int qpow(int r)
{
	ll base = 10, ans = 1;
	while (r)
	{
		if (r & 1)
			ans *= base;
		base *= base;
		r >>= 1;
	}
	return ans;
}
int find()
{
	ll res=0, lim=0;
	if (n%7==0) lim = n/7;
	else lim = n/7+1;
	for (ll i=qpow(lim-1); i<1e19; i++)
	{
		res = check(i);
		if (res == n) return i;
		else
		if (res > qpow(lim)) {return -1;}
	}
	return -1;
}
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	sticks[0]=6; sticks[1]=2; sticks[2]=5; sticks[3]=5; sticks[4]=4;
	sticks[5]=5; sticks[6]=6; sticks[7]=3; sticks[8]=7; sticks[9]=6;
	scanf("%d", &T);
	for (int i=0; i<T; i++)
	{
		scanf("%d", &n);
		anss[i] = find();
	}
	for (int i=0; i<T; i++)
		printf("%d\n", anss[i]);
	return 0;
}
