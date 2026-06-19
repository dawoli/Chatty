#include <bits/stdc++.h>
using namespace std;
int a[20],c[20],t,n;
long long ans,sum;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=0;i<n;++i)
			scanf("%d",&a[i]);
		if (n>20) printf("0\n");
		ans = 0;
		for (int i=0;i<(1<<n);++i)
		{
			int t=i;
			for (int j=0;j<n;++j)
			{
				c[j] = t&1;
				t >>= 1;
			}
			int p1=-1,p2=-1;
			sum = 0;
			for (int j=0;j<n;++j)
			{
				if (c[j]==0)
				{
					if (p1>=0 && a[p1]==a[j]) sum += a[j];
					p1 = j;
				}
				else
				{
					if (p2>=0 && a[p2]==a[j]) sum += a[j];
					p2 = j;
				}
			}
			ans = max(ans,sum);
		}
		printf("%lld\n",ans);
	}
    return 0;
}
