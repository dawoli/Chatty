#include <bits/stdc++.h>
using namespace std;

int dp1[25][55];
string dp2[160][1010];
int arr[8] = {-1, -1, 1, 7, 4, 2, 0, 8};
string arr2[8] = {"-1", "-1", "1", "7", "4", "2", "0", "8"};
//如果是首位的话arr[6]为6 
 
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		if (n == 1)
		{
			cout << -1 << endl;
		}
		else if (n % 7 == 0)
		{
			for (int i = 1; i <= n / 7; i++)
				cout << 8;
			cout << endl;
		}
		else if (n % 7 == 1)
		{
			cout << 10;
			for (int i = 1; i <= (n-8) / 7; i++)
				cout << 8;
			cout << endl;
		}
		else if (n <= 50)
		{
			for (int i = 0; i <= 20; i++)
				for (int j = 0; j <= 50; j++)
					dp1[i][j] = 1000000000;
			for (int i = 1; i <= n / 7 + 1; i++)
			{
				for (int j = n - 2 * i; j >= max(0, n - 7 * i); j--)
				{
					if (i == 1 && n - j == 6)	dp1[i][j] = 6;
					else if (i == 1)
					{
						dp1[i][j] = arr[n-j];
					}
					else
					{
						//前7个 
						int tmp = dp1[i-1][j+2], cur = j + 2;
						for (int k = j + 3; k <= j + 7; k++)
						{
							if (dp1[i-1][k] < tmp)
							{
								tmp = dp1[i-1][k];
								cur = k;
							}
						}
						dp1[i][j] = min(dp1[i-1][j], tmp * 10 + arr[cur-j]);
					}
				}
			}
			cout << dp1[n/7+1][0] << endl;
		}
//		else if (n <= 1000 || n == 18)
//		{
//			for (int i = 0; i <= 150; i++)
//				for (int j = 0; j <= 1000; j++)
//					dp2[i][j] = "!";
//			for (int i = 1; i <= n / 7 + 1; i++)
//			{
//				for (int j = n - 2 * i; j >= max(0, n - 7 * i); j--)
//				{
//					if (i == 1 && n - j == 6)	dp2[i][j] = "6";
//					else if (i == 1)
//					{
//						dp2[i][j] = arr2[n-j];
//						cout << dp2[i][j] << endl;
//					}
//					else
//					{
//						string tmp = dp2[i-1][j+2];
//						int cur = j + 2;
//						for (int k = j + 3; k <= j + 7; k++)
//						{
//							if (dp2[i-1][k] != "!" && (dp2[i-1][k].size() < tmp.size() || (dp2[i-1][k].size() == tmp.size() && dp2[i-1][k] < tmp)))
//							{
//								tmp = dp1[i-1][k];
//								cur = k;
//							}
//						}
//						string tp = tmp + arr2[cur-j];
//						if (dp2[i-1][j] != "!" && (dp2[i-1][j].size() < tp.size() || (dp2[i-1][j].size() == tp.size() && dp2[i-1][j].size() < tp.size())))
//						{
//							dp2[i][j] = dp2[i-1][j];
//						}
//						else
//						{
//							dp2[i][j] = tp;
//						}
//					}
//				}
//			}
//			for (int i = 1; i <= n / 7 + 1; i++)
//				for (int j =0; j <= n; j++)
//					cout << dp1[i][j] << endl;
//			cout << dp1[n/7+1][0] << endl;
//		}
	}
	return 0;
}
