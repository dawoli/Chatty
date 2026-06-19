#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int num[500010];
int ans[500010];

struct qv
{
	long long l, r;
}chong[500010];

bool cmp(qv x, qv y)
{
	return x.r < y.r || (x.r == y.r &&x.l < y.l);
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> num[i];	
		ans[i] = ans[i - 1] ^ num[i];
		//cout << ans[i] << " ";
	}
//	cout << endl;
	long long cnt = 0;
	for(int i = 1; i <= n ; i++)
	{
		for(int j = i; j <= n; j++)
		{
			int xyz = ans[j] ^ ans[i - 1];
			if(xyz == k)
			{
				cnt++;
				chong[cnt].l = i;
				chong[cnt].r = j;
			}

		//	cout << xyz << " ";
		}
	}
//	cout << endl;
	sort(chong + 1, chong + cnt + 1, cmp);
	long long xr = chong[1].r;
	long long anscnt = 0;
	if(xr != 0) anscnt = 1;
	for(int i = 1; i <= cnt; i++)
	{
		if(chong[i].l > xr)
		{
			anscnt++;
			xr = chong[i].r;
		}
	//	cout << chong[i].l << " " << chong[i].r << endl;
	}
	cout << anscnt;
	return 0;
}
