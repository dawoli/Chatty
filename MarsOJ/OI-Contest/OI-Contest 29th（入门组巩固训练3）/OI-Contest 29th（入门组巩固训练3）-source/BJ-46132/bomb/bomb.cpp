#include<iostream>
using namespace std;


int main()
{
	//freopen("bomb.in", "r", stdin);
	//freopen("bomb.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for(int k = 0; k < t; k++)
	{
		int n, m;
		cin >> n >> m;
		char a[1005][1005];
		int cnt = 0;
		for(int i = 0; i < n ; i++)
		{
			for(int j = 0; j < m; j++)
			{
				a[i][j] = getchar();
				if(a[i][j]=='$')
				{
					cnt++;
				}
			}
		}
		cout << (m-1) << ' ' << cnt << '\n';
	}
	return 0;
}
