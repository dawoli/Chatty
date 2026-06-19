#include <bits/stdc++.h>
using namespace std;
int frq;
int n;
const int N = 1e5 + 7;
int a[N][4]; 
int dp[210][210][210];
int dp1[210][210];
int dp2[210];
struct node
{
	int per,club,num;
};
bool cmp(node a,node b)
{
	return a.num > b.num;
}
bool ch[N];
int cnt[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin >> frq;
	while(frq--)
	{
		cin >> n;
		if(n <= 30)
		{
			for(int t = 1;t <= n;t++)
			{
				for(int i = 1;i <= 3;i++)
				{
					cin >> a[t][i];
				}
			}
			int maxn = -1;
			for(int i = n / 2;i >= 0;i--)
			{
				for(int j = n / 2;j >= 0;j--)
				{
					for(int k = n / 2;k >= 0;k--)
					{
						dp[i][j][k] = 0;
					}
				}
			}
			for(int t = 1;t <= n;t++)
			{
				for(int i = n / 2;i >= 0;i--)
				{
					for(int j = n / 2;j >= 0;j--)
					{
						for(int k = n / 2;k >= 0;k--)
						{
							int x,y,z;
							if(i == 0)
							{
								x = -1;
							}
							else
							{
								x = dp[i - 1][j][k] + a[t][1];
								//cout << a[t][1] << " " << x << endl; 
							}
							if(j == 0)
							{
								y = -1;
							}
							else
							{
								y = dp[i][j - 1][k] + a[t][2];
							}
							if(k == 0)
							{
								z = -1;
							}
							else
							{
								z = dp[i][j][k - 1] + a[t][3];
							}
							dp[i][j][k] = max({x,y,z,0});
							maxn = max(maxn,dp[i][j][k]);
							//cout << i << " " << j << " " << k << " " << dp[i][j][k] << " " << x << " " << y << " " << z << endl;
						}
					}
				}
			}
			cout << maxn << endl;
		}
		else if(n == 200)
		{
			for(int t = 1;t <= n;t++)
			{
				for(int i = 1;i <= 3;i++)
				{
					cin >> a[t][i];
				}
			}
			int maxn = -1;
			for(int i = n / 2;i >= 0;i--)
			{
				for(int j = n / 2;j >= 0;j--)
				{
					dp1[i][j] = 0;
				}
			}
			for(int t = 1;t <= n;t++)
			{
				for(int i = n / 2;i >= 0;i--)
				{
					for(int j = n / 2;j >= 0;j--)
					{
						int x,y,z;
						if(i == 0)
						{
							x = -1;
						}
						else
						{
							x = dp1[i - 1][j] + a[t][1];
						}
						if(j == 0)
						{
							y = -1;
						}
						else
						{
							y = dp1[i][j - 1] + a[t][2];
						}
						z = dp1[i][j];
						dp1[i][j] = max({x,y,z,0});
						maxn = max(maxn,dp1[i][j]);
					}
				}
			}
			cout << maxn << endl;
		}
		else
		{
			bool flag = 1;
			for(int t = 1;t <= n;t++)
			{
				for(int i = 1;i <= 3;i++)
				{
					cin >> a[t][i];
				}
				if(a[t][2] != 0 || a[t][3] != 0) flag = 0;
			}
			if(flag)
			{
				int maxn = -1;
				for(int i = n / 2;i >= 0;i--)
				{
					dp2[i] = 0;
				}
				for(int t = 1;t <= n;t++)
				{
					for(int i = n / 2;i >= 0;i--)
					{
						int x,y,z;
						if(i == 0)
						{
							x = -1;
						}
						else
						{
							x = dp2[i - 1] + a[t][1];
						}
						dp2[i] = x;
						maxn = max(maxn,dp2[i]);
						//cout << i << " " << j << " " << k << " " << dp[i][j][k] << " " << x << " " << y << " " << z << endl;
					}
				}
				cout << maxn << endl;
			}
			else
			{
				vector <node> b;
				int ans = 0;
				for(int t = 1;t <= n;t++)
				{
					for(int i = 1;i <= 3;i++)
					{
						cin >> a[t][i];
						b.push_back({t,i,a[t][i]});
					}
					cnt[t] = 0;
					ch[t] = 0;
				}
				sort(b.begin(),b.end(),cmp);
				for(int t = 0;t < int(b.size());t++)
				{
					if(!ch[b[t].per] && cnt[b[t].club] < n / 2)
					{
						ch[b[t].per] = 1;
						cnt[b[t].club]++;
						ans += b[t].num;
					}
				}
				cout << ans << endl;
			}
		}
	}
	return 0;
}
