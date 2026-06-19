#include<bits/stdc++.h>
using namespace std;

int a[15][200010], maxn = -1e9, cnt = 1, n;
bool flag[200010];

int grade()
{
	int sum = 0;
	bool blue_flag = false, red_flag = false; 
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == true)
		{
			if (red_flag == true && i != 1)			
			{
				for (int j = 1; j < i; j++)
				{
					if (a[cnt][i] == a[cnt][j])
					{
						sum += a[cnt][i];
						break;
					}
				} 
			}
			red_flag = true;
		}
		else
		{
			if (blue_flag == true && i != 1)			
			{
				for (int j = 1; j < i; j++)
				{
					if (a[cnt][i] == a[cnt][j])
					{
						sum += a[cnt][i];
						break;
					}
				} 
			}
			blue_flag = true;
		}
	}
	return sum;
}

void dfs(int step, int n)
{
	if (step == n + 1)
	{
		maxn = max (grade(), maxn);
		return ;
	}
	flag[step] == true;
	dfs(step + 1, n);
	flag[step] == false;
	dfs(step + 1, n);
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) 
	{
		cnt = 1;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[cnt][i];			
		}
		dfs(1, n);
		cout << maxn << endl;
	}
	return 0; 
 } 
