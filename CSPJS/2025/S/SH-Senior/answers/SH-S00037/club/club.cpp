#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
const int MAX = (int)(-1e9);
int n, ansr = MAX, ans;
int mxt1, mxt2, mxt3;
int a[N], t1[N], t2[N], t3[N];
bool biao[N];

void dfs(int dep, int i)
{
	if (dep == n)
	{
		if (ans > ansr)s
		{
			ansr = ans;
		} 
		return ;
	}

	if (mxt1 < (n/2))
	{
		ans += t1[i];
		mxt1++;
		//printf("c---t1[%d]=%d\n", i, t1[i]);
		dfs(dep+1, i+1);
		ans -= t1[i];
		mxt1--;
	}

	if (mxt2 < (n/2))
	{ 
		ans += t2[i];
		mxt2++;
		//printf("c---t2[%d]=%d\n", i, t2[i]);
		dfs(dep+1, i+1);
		ans -= t2[i];
		mxt2--;
	}
	
	if (mxt3 < (n/2))
	{
		ans += t3[i];
		mxt3++;
		//printf("c---t3[%d]=%d\n", i, t3[i]);
		dfs(dep+1, i+1);
		ans -= t3[i];
		mxt3--;
	}

}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d", &t1[i], &t2[i], &t3[i]);
		}
		dfs(0, 0);
		printf("%lld\n", ansr);
		ans = 0;
		ansr = MAX;
	}
	return 0;
}
