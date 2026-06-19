#include <iostream>
#include <cstdio>
using namespace std;

int l[100005],s[1005][2005];

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin >> t;
	while (t--)
	{
		int n,kk,q;
		cin >> n >> kk >> q;
		for (int i = 1;i <= n;i++)
		{
			cin >> l[i];
			for (int j = 1;j <= l[i];j++)
			{
				cin >> s[i][j];
			}
		}
		for (int i = 1;i <= q;i++)
		{
			int r,c;
			cin >> r >> c;
			if (r == 1)
			{
				bool flag = false;
				for (int i = 1;i <= n;i++)
				{
					for (int j = 1;j <= l[i];j++)
					{
						if (s[i][j] == 1)
						{
							for (int k = j;k <= min(j + kk,l[i]);k++)
							{
								if (s[i][k] == c)
								{
									flag = true;
									break;
								}
							}
						}
						if (flag) break;
					}
					if (flag) break;
				}
				if (flag) cout << 1 << endl;
				else cout << 0 << endl;
			} 
		}
		
	}
	return 0;
}
