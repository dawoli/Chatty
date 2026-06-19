#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+5;
int n,k,a[MAXN],f[MAXN][MAXN];
bool s[MAXN];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i<=n;i++)
	{
		cin >> a[i];
		f[i][i] = a[i];
	}
	for (int i = 1;i<=n;i++)
	{
		for (int j = i+1;j<=n;j++)
		{
			f[i][j] = a[j] ^ f[i][j-1];
		} 
	}
	int l = 0,cnt = 0;
	for (int t = 1;t<n;t++)
	{
		for (int i = 1;i<=n;i++)
		{
			int j = i + l;
			if (j>n) break;
			bool flag = false;
			for (int p = i;p<=j;p++)
			{
				if (s[p]==true)
				{
					flag = true;
					break;
				}
			}
			if (f[i][j]==k&&flag == false)
			{
				cnt++;
				for (int p = i;p<=j;p++)
				{
					s[p] = true;
				}
			}
		}
		l++;
	}
	cout << cnt;
	return 0;
 }
