#include <bits/stdc++.h>
using namespace std;
const int N=100002;
int c[N],n,mxv,mnv,ans; 
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	mnv = 100000;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		mxv = max(mxv,x);
		mnv = min(mnv,x);
		++c[x];
	}
	ans = n;
	for (int i=mnv+1;i<=mxv;++i)
	{
		int tv=c[i];
		while (c[mnv]<tv)
		{
			tv -= c[mnv];
			ans -= c[mnv];
			c[mnv] = 0;
			while (mnv<i && c[mnv]==0) ++mnv;
		}
		if (mnv<i)
		{
			c[mnv] -= tv;
			ans -= tv;
		}
	}
	printf("%d\n",ans);
    return 0;
}
