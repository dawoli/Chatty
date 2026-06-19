#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b,c,r,cnt = 1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%lld",&b);
	for(int i = 2 ; i <= n * m ; i++)
	{
		scanf("%lld",&a);
		if(a > b) cnt++;
	}
	if(cnt % n != 0)
	{
		c = cnt/n+1;
		if(c % 2 == 0) r = m - (cnt%n) + 1;
		else r = cnt%n;
	}
	else
	{
		c = cnt/n;
		if(c % 2 == 0) r = m - n + 1;
		else r = n;
	}
	printf("%lld %lld\n",c,r);
	return 0;
}
