#include<bits/stdc++.h>
using namespace std;
int n, w[100005][3], dp[205][205][205], ans;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin>>T;
	while(T--)
	{
		ans = 0;
		cin>>n;
		if(n > 200)
		{
			bool flag1 = 1, flag2 = 1;
			for(int i = 1; i <= n; i++) 
			{
				for(int j = 1; j <= 3; j++) 
				{
					cin>>w[i][j];
				}
				if(w[i][2] != 0 || w[i][3] != 0) flag1 = 0;
				if(w[i][3] != 0) flag2 = 0;
			}
			if(flag1) // A
			{
				priority_queue<int> q;
				for(int i = 1; i <= n; i++) q.push(w[i][1]);
				int t = n / 2;
				while(t--)
				{
					ans += q.top(); q.pop();
				}
				cout<<ans<<endl;
				continue;
			}
			if(flag2) // B
			{
				
			}
		}
		for(int i = 1; i <= n; i++) for(int j = 1; j <= 3; j++) cin>>w[i][j];
		for(int i = 1; i <= n; i++)
		{
			for(int a = n / 2; a >= 0; a--)
			{
				for(int b = n / 2; b >= 0; b--)
				{
					int c = i - a - b;
					if(c < 0 || c > n / 2) continue;
					dp[a][b][c] = 0;
					if(a) dp[a][b][c] = max(dp[a][b][c], dp[a - 1][b][c] + w[i][1]);
					if(b) dp[a][b][c] = max(dp[a][b][c], dp[a][b - 1][c] + w[i][2]);
					if(c) dp[a][b][c] = max(dp[a][b][c], dp[a][b][c - 1] + w[i][3]);
					if(i == n) ans = max(ans, dp[a][b][c]);
				}
			}	
		}
		cout<<ans<<endl;
	}
	/*
	1
	4
	10 9 8
	4 5 9
	3 2 0
	0 1 0
	*/
	return 0;
} 
