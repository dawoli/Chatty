#include <bits/stdc++.h>
using namespace std;
int sum;
int main()
{
	freopen("bomb.in", "r", stdin);
	freopen("bomb.out", "w", stdout);
	int t, n, m;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n >> m;
		for(int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if(c == '$')
			{
				sum++;
			}
		}
		cout << sum << " " << m - 1 << endl;
		sum = 0;
	}
	return 0;
}
