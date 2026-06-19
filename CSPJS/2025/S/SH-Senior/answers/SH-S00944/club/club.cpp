#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int a1[N],a2[N],a3[N];
int n,t;
int maxn = 0;

bool cmp(const int & a,const int & b)
{
	return a > b;
}

void dfs(int l1,int l2,int l3,int sum)
{
	if (l1 + l2 + l3 == n+1)
	{
		maxn = max(maxn,sum);
		return;
	}
	if (l1 > n/2 || l2 > n/2 || l3 > n/2)
	{
		return;
	}
	dfs(l1+1,l2,l3,sum+a1[l1+l2+l3+1]);
	dfs(l1,l2+1,l3,sum+a2[l1+l2+l3+1]);
	dfs(l1,l2,l3+1,sum+a3[l1+l2+l3+1]);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	for (int k = 1;k <= t;k++)
	{
		maxn = 0;
		bool x1 = true,x2 = true;
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			cin >> a1[i] >> a2[i] >> a3[i];
			if (a3[i] != 0)
			{
				x1 = false;
				x2 = false;
			}
			if (a2[i] != 0)
			{
				x1 = false;
			}
		}
		if (x1)
		{
			sort(a1+1,a1+n+1,cmp);
			int sum = 0;
			for (int i = 1;i <= n/2;i++)
			{
				sum += a1[i];
			}
			cout << sum << endl;
		}
//		else if (x2)
//		{
//			int dp[N/2+5][N/2+5] = {};
//			for (int i = 1;i <= n;i++)
//			{
//				for (int j = 0;j < i;j++)
//				{
//					dp[n/2-j-1][n/2+j+1-i] = max(dp[n/2-j-1][n/2+j+1-i],dp[n/2-j][n/2+j+1-i]+a1[i]);
//					dp[n/2-j][n/2+j-i] = max(dp[n/2-j][n/2+j-i],dp[n/2-j][n/2+j+1-i]+a2[i]);
//				}
//			}
//			cout << dp[0][0] << endl;
//		}
		else
		{
			dfs(0,0,0,0);
			cout << maxn << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
