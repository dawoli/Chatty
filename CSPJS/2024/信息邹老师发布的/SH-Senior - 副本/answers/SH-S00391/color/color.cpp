#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MXN = 2e5 + 5;
int n;
long long ans,last[MXN],a[MXN],c[MXN],prbbc[MXN],spbc[MXN];
bool a_clr[MXN]; //0 blue    1 red

void dfs(int step,long long pts)
{
	if (pts + spbc[n] - spbc[step - 1] <= ans) return;
	if (step > n)
	{
		ans = max(ans,pts);
		return;
	}
	a_clr[step] = 0;
	if (a_clr[step] == a_clr[last[step]]) c[step] = prbbc[step];
	dfs(step + 1,pts + c[step]);
	c[step] = 0;
	a_clr[step] = 1;
	if (a_clr[step] == a_clr[last[step]]) c[step] = prbbc[step];
	dfs(step + 1,pts + c[step]);
	c[step] = 0;
	a_clr[step] = 0;
}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin >> t;
	while (t--)
	{
		memset(last,0,sizeof(last));
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		memset(prbbc,0,sizeof(prbbc));
		memset(spbc,0,sizeof(spbc));
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
			for (int j = i - 1;j >= 1;j--)
			{
				if (a[j] == a[i])
				{
					last[i] = j;
					break;
				}
			}
			if (last[i] != 0) prbbc[i] = a[i];
			spbc[i] = spbc[i - 1] + prbbc[i];
		}
		ans = 0;
		dfs(1,0);
		cout << ans << endl;
	}
	return 0;
}
