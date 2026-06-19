#include<bits/stdc++.h>
using namespace std;
int n,T;
struct mem
{
	int a;
	int b;
	int c;
	int ta;
	int tb;
}a[100005];
bool cmp(mem x,mem y)
{
	return x.a - x.b > y.a - y.b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 1;i <= n;i++)
		{
			int x,y,z,f[5];
			scanf("%d%d%d",&x,&y,&z);
			a[i].a = max({x,y,z});
			a[i].c = min({x,y,z});
			a[i].b = x + y + z - a[i].a - a[i].c;
			f[1] = x;
			f[2] = y;
			f[3] = z;
			for(int j = 1;j <= 3;j++)
			{
				if(a[i].a == f[j])
				{
					a[i].ta = j;
				}
				else if(a[i].b == f[j])
				{
					a[i].tb = j;
				}
			}
		}
		sort(a+1,a+n+1,cmp);
		int ans = 0,cnt[5] = {};
		for(int i = 1;i <= n;i++)
		{
			if(cnt[a[i].ta] < n/2)
			{
				ans += a[i].a;
				cnt[a[i].ta]++;
			}
			else
			{
				ans += a[i].b;
				cnt[a[i].tb]++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
