#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int NR = 1e5+5;
struct node{int a1, a2, a3;};
int n;
node a[NR];

bool cmp1(node x, node y)
{
	return (x.a1 - max(x.a2, x.a3)) > (y.a1 - max(y.a2, y.a3));
}
bool cmp2(node x, node y)
{
	return (x.a2 - max(x.a1, x.a3)) > (y.a2 - max(y.a1, y.a3));
}
bool cmp3(node x, node y)
{
	return (x.a3 - max(x.a1, x.a2)) > (y.a3 - max(y.a1, y.a2));
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%lld", &T);
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld%lld%lld", &a[i].a1, &a[i].a2, &a[i].a3);
		}
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i].a1 > a[i].a2 && a[i].a1 > a[i].a3) cnt1++;
			if(a[i].a2 > a[i].a1 && a[i].a2 > a[i].a3) cnt2++;
			if(a[i].a3 > a[i].a1 && a[i].a3 > a[i].a2) cnt3++;
		}
		if(cnt1 <= n/2 && cnt2 <= n/2 && cnt3 <= n/2)
		{
			for(int i = 1; i <= n; i++)
			{
				int maxn = max(max(a[i].a1, a[i].a2), a[i].a3);
				ans += maxn;
			}
		}
		else
		{
			if(cnt1 > n/2)
			{
				sort(a+1,a+n+1,cmp1);
				for(int i = 1; i <= n/2; i++)
				{
					ans += a[i].a1;
				}
				for(int i = n/2+1; i <= n; i++)
				{
					ans += max(a[i].a2, a[i].a3);
				}
			}
			else if(cnt2 > n/2)
			{
				sort(a+1,a+n+1,cmp2);
				for(int i = 1; i <= n/2; i++)
				{
					ans += a[i].a2;
				}
				for(int i = n/2+1; i <= n; i++)
				{
					ans += max(a[i].a1, a[i].a3);
				}
			}
			else if(cnt3 > n/2)
			{
				sort(a+1,a+n+1,cmp3);
				for(int i = 1; i <= n/2; i++)
				{
					ans += a[i].a3;
				}
				for(int i = n/2+1; i <= n; i++)
				{
					ans += max(a[i].a1, a[i].a2);
				}
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
