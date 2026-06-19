#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005];
//vector<int> vt[2005];
int c[100005];
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(n <= 15)
		{
			bool b[16];
			for(int i = 0;i < n;i++)
			{
				cin >> a[i];
			}
			int ans = 0;
			for(int i = 0;i < (1 << (n - 1));i++)
			{
				memset(b, 0, sizeof(b));
				int j = 1, k = i, cnt = 0;
				while(k > 0)
				{
					if(k & 1 == 1) b[j] = 1;
					k >>= 1;
					j++;
				}
				for(int i = 1;i < n;i++)
				{
					int j = i - 1;
					while(j >= 0 && b[j] != b[i]) j--;
					if(j >= 0 && a[j] == a[i]) cnt += a[i];
				}
				ans = max(ans, cnt);
			}
			cout << ans << endl;
			continue;
		}
//		for(int i = 0;i <= 2000;i++)
//		{
//			vt[i].reserve(0);
//		}
//		for(int i = 0;i < n;i++)
//		{
//			cin >> a[i];
//		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
