#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,cnt=0,a[100009];

signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%lld",&a[i]);
	for(int i=2;i<=n*m;i++)
	{
		if(a[i]>a[1])
			cnt++;
	}
	cnt++;
//	printf("%lld\n",cnt);
	ll cl=(ll)ceil(1.*cnt/n);
	ll md=cnt%n;
	if(md==0) md=n;
	if(cl&1)
		printf("%lld %lld\n",cl,md);
	else printf("%lld %lld\n",cl,n-md+1);
	return 0;
}
