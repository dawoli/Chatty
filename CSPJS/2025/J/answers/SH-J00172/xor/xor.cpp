#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int sum[N], a[N], n, m, cnt, p, ans, bj[N], num, ff, gg;
struct dat{int l,r,nm;};
dat f[N];

bool pd(int x)
{
	for (int i = f[x].l; i <= f[x].r; i++)
	{
		if (bj[i] > 0) return false;
	}
	return true;
}

//void gpd()
//{
//	for (int j = 1; j <= cnt; j++)
//	{
//		for (int i = f[j].l; i <= f[j].r; i++)
//		{
//			f[j].nm = max(f[j].nm, bj[i]-1);
//		}
//	}
//}

//bool cmp(dat x, dat y)
//{
//	return x.nm > y.nm;
//}

void dfs(int step, int sum)
{
	if (step > cnt)
	{
		ans = max(ans, sum);
		return;
	}
	if (pd(step)) 
	{
		for (int i = f[step].l; i <= f[step].r; i++) bj[i] = 1;
		dfs(step+1, sum+1);
	}
	for (int i = f[step].l; i <= f[step].r; i++) bj[i] = 0;
	dfs(step+1, sum);
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> m;
	ff = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = a[i] ^ sum[i-1];
		if (a[i] > 1) ff = 0;
	}
	if (ff == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 1) gg++;
		}
		if (m == 1) cout << gg << endl;
		else cout << n-gg << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			p = sum[j] ^ sum[j-i];
			if (p == m)
			{
				cnt++;
				f[cnt].l = j-i+1;
				f[cnt].r = j;
				//for (int k = j-i+1; k <= j; k++) bj[k]++;
				//cout << j-i+1 << " " << j << " " << sum[j] << " " << sum[j-i] << endl;
				if (cnt >= 500005) break;
			}
		}
		if (cnt >= 500005) break;
	}
//	gpd();
//	while (!pd()) 
//	{
//		num++;
//		for (int i = f[1].l; i <= f[1].r; i++)
//		{
//			bj[i]--;
//		}
//	}
//	cout << cnt-num << endl;
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}
