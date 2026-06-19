#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int dp[30];
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin.tie();
	cout.tie();
	memset(dp,0x3f,sizeof(dp));
	dp[1] = dp[0] = -1;
	dp[2] = 1;
	dp[3] = 7;
	dp[4] = 4;
	dp[5] = 2;
	dp[6] = 6;
	dp[7] = 8;
	for(int i = 2;i <= 21;i++)
	{
		dp[i + 2] = min(dp[i + 2],dp[i] * 10 + 1);
		dp[i + 3] = min(dp[i + 3],dp[i] * 10 + 7);
		dp[i + 4] = min(dp[i + 4],dp[i] * 10 + 4);
		dp[i + 5] = min(dp[i + 5],dp[i] * 10 + 2);
		dp[i + 6] = min(dp[i + 6],dp[i] * 10);
		dp[i + 7] = min(dp[i + 7],dp[i] * 10 + 8);
	}
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		if(n <= 21) cout << dp[n] << endl;
		else
		{
			int x = (n - 1) % 7 + 15,y = (n - 1) / 7 - 2;
			cout << x;
			while(y--) cout << 8;
			cout << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
