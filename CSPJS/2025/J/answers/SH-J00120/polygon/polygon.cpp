# include <iostream>
using namespace std;
const int MOD = 998244353;
int ans = 0, a[5000], n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
	cin >> a[i];
	}
	for (int i = 1; i <= n; i ++)
	{
		for(int j = i + 1; j <= n; j ++)
		{
			for (int k = j+ 1; k <= n; k ++)
			{
				if (a[i] + a[j] > a[k]) ans ++;
			}
		}
	}
	cout << ans;
	return 0;	
} 
